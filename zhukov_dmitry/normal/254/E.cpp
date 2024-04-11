#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
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

FILE *g_f_;
char *g_str_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(x) (g_str_ = gets(x))
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int MAXW = 802;

int n, v, m;
int a[512];
int b[512];
int l[512];
int r[512];
int t[512];
int d0[412][812];
int d1[412][812];
int pa0[412][812];
int pa1[412][812][2];
VI res[412];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
//	freopen("test.txt", "rt", stdin);
#else
	freopen("output.txt", "wt", stdout);
#endif
	freopen("input.txt", "rt", stdin);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &v);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%d%d%d", &l[i], &r[i], &t[i]);
		l[i]--;
		r[i]--;
	}

	memset(d0, 0x80, sizeof(d0));
	forn(i, n)
	{
		int k = 0;
		forn(j, m)
		{
			if (l[j] <= i && r[j] >= i)
			{
				b[k++] = j;
			}
		}

		d0[i][0] = 0;
		forn(j1, k)
		{
			int j = b[j1];
			ford(l, MAXW)
			{
				int z;
				if (d0[i][l] >= 0 && (z = l + t[j]) < MAXW)
				{
					int tmp = d0[i][l] + 1;
					if (d0[i][z] < tmp)
					{
						d0[i][z] = tmp;
//						pa0[i][z] = j;
					}
				}
			}
		}
	}

	memset(d1, 0x80, sizeof(d1));
	d1[0][0] = 0;
	forn(i, n)
	{
		ford(j, MAXW)
		{
			if (d1[i][j] >= 0)
			{
				int ma = j - v + a[i];
				if (ma >= MAXW) ma = MAXW - 1;
				For(k, 0, ma)
				{
					if (d0[i][k] >= 0)
					{
						int z;
						int next = ma - k;
						if (next > a[i]) next = a[i];
						if (d1[i + 1][next] < (z = d1[i][j] + d0[i][k]))
						{
							d1[i + 1][next] = z;
							pa1[i + 1][next][0] = k;
							pa1[i + 1][next][1] = j;
						}
					}
				}
			}
		}
	}

	int ans = -1;
	int y = -1;
	forn(i, MAXW)
	{
		if (d1[n][i] > ans)
		{
			ans = d1[n][i];
			y = i;
		}
	}

	ford(i, n)
	{
		int t0 = pa1[i + 1][y][0];
		int t1 = pa1[i + 1][y][1];

		{
			int w = t0;
			int p = d0[i][w];
			int k = 0;
			forn(j, m)
			{
				if (l[j] <= i && r[j] >= i)
				{
					b[k++] = j;
				}
			}

			memset(d0[i], 0x80, sizeof(d0[i]));
			d0[i][0] = 0;
			forn(j1, k)
			{
				int j = b[j1];
				ford(l, w + 1)
				{
					int z;
					if (d0[i][l] >= 0 && (z = l + t[j]) < MAXW)
					{
						int tmp = d0[i][l] + 1;
						if (d0[i][z] < tmp)
						{
							d0[i][z] = tmp;
							pa0[tmp - 1][z] = j;
						}
					}
				}
			}

			while (p--)
			{
				int x = pa0[p][w];
				res[i].pb(x);
				w -= t[x];
			}
		}

		y = t1;
	}

	printf("%d\n", ans);
	forn(i, n)
	{
		printf("%d", (int)res[i].sz);
		sort(res[i].begin(), res[i].end());
		forn(j, res[i].sz)
		{
			if (j && res[i][j] == res[i][j - 1]) for(;;);
			printf(" %d", res[i][j] + 1);
		}
		puts("");
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}