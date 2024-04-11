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

struct tp{int x, y;};

int n, xx = 0, yy = 0;
tp p[1024];
int xs[1024];
int ys[1024];
bool b[1024][1024];
int xr[1024][2];
int yr[1024][2];
int kh, kv;
int nh[1024][1024];
int nv[1024][1024];
VI a[10240];
VI ra[10240];
bool u[10240];
int p1[10240];
int pa[10240];
bool u2[10240];
int ah[10240][4];
int av[10240][4];
bool bh[1024][1024];
bool bv[1024][1024];

bool find(int k)
{
	u[k] = true;
	for (int v : a[k])
	{
		if (pa[v] == -1)
		{
			pa[v] = k;
			return true;
		}
	}
	for (int v : a[k])
	{
		if (pa[v] == -1 || (!u[pa[v]] && find(pa[v])))
		{
			pa[v] = k;
			return true;
		}
	}
	return false;
}

void dfs(int k)
{
	u[k] = true;
	for (int v : a[k])
	{
		if (pa[v] == k) continue;
		if (!u2[v])
		{
			u2[v] = true;
			dfs(pa[v]);
		}
	}
}

void solve()
{
	memset(p1, 0xff, sizeof(p1));
	forn(i, kv)
	{
		if (pa[i] != -1)
		{
			p1[pa[i]] = i;
		}
	}
	clr(u);
	clr(u2);
	forn(i, kh)
	{
		if (p1[i] == -1)
		{
			dfs(i);
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		xs[xx++] = p[i].x;
		ys[yy++] = p[i].y;
	}
	sort(xs, xs + xx);
	xx = unique(xs, xs + xx) - xs;
	sort(ys, ys + yy);
	yy = unique(ys, ys + yy) - ys;
	forn(i, n)
	{
		p[i].x = lower_bound(xs, xs + xx, p[i].x) - xs;
		p[i].y = lower_bound(ys, ys + yy, p[i].y) - ys;
	}
	clr(b);
	forn(i, n)
	{
		b[p[i].x][p[i].y] = true;
	}
	forn(j, yy)
	{
		yr[j][0] = xx + 1;
		yr[j][1] = -1;
	}
	forn(i, xx)
	{
		xr[i][0] = yy + 1;
		xr[i][1] = -1;
		forn(j, yy)
		{
			if (b[i][j])
			{
				uin(xr[i][0], j);
				uax(xr[i][1], j);
				uin(yr[j][0], i);
				uax(yr[j][1], i);
			}
		}
	}
	memset(nh, 0xff, sizeof(nh));
	memset(nv, 0xff, sizeof(nv));
	kh = kv = 0;
	forn(i, xx)
	{
		if (xr[i][1] < 0) continue;
		int sty = -1;
		forn(j, yy)
		{
			if (j < xr[i][0] || j > xr[i][1]) continue;
			if (b[i][j])
			{
				if (sty != -1)
				{
					kh++;
					sty = -1;
				}
			}
			else
			{
				nh[i][j] = kh;
				sty = j;
			}
		}
		if (sty != -1)
		{
			kh++;
		}
	}
	forn(j, yy)
	{
		if (yr[j][1] < 0) continue;
		int stx = -1;
		forn(i, xx)
		{
			if (i < yr[j][0] || i > yr[j][1]) continue;
			if (b[i][j])
			{
				if (stx != -1)
				{
					kv++;
					stx = -1;
				}
			}
			else
			{
				nv[i][j] = kv;
				stx = i;
			}
		}
		if (stx != -1)
		{
			kv++;
		}
	}

/*	forn(i, xx)
	{
		forn(j, yy)
		{
			cerr << b[i][j];
		}
		cerr << endl;
	}
	cerr << "---" << endl;
	forn(i, xx)
	{
		forn(j, yy)
		{
			cerr << nh[i][j] << " ";
		}
		cerr << endl;
	}
	cerr << "---" << endl;
	forn(i, xx)
	{
		forn(j, yy)
		{
			cerr << nv[i][j] << " ";
		}
		cerr << endl;
	}
	cerr << "---" << endl;
*/
	forn(i, xx)
	{
		forn(j, yy)
		{
			if (nh[i][j] != -1)
			{
				if (nv[i][j] != -1)
				{
					a[nh[i][j]].pb(nv[i][j]);
					ra[nv[i][j]].pb(nh[i][j]);
				}
			}
		}
	}
	
	memset(pa, 0xff, sizeof(pa));
	clr(u);
	forn(i, kh)
	{
		if (find(i))
		{
			memset(u, 0, kh * sizeof(u[0]));
		}
	}
/*	cerr << "kh=" << kh << endl;
	cerr << "kv=" << kv << endl;
	forn(i, kv)
	{
		cerr << pa[i] << " ";
	}
	cerr << endl;
*/
	memcpy(bh, b, sizeof(b));
	memcpy(bv, b, sizeof(b));

	solve();
/*	forn(i, kh)
	{
		cerr << i << " " << u[i] << endl;
	}
	cerr << "-----" << endl;
	forn(i, kv)
	{
		cerr << i << " " << u2[i] << endl;
	}
	cerr << "-----" << endl;
*/
	forn(i, xx)
	{
		forn(j, yy)
		{
			if (nh[i][j] >= 0 && u[nh[i][j]]) bh[i][j] = true;
			if (nv[i][j] >= 0 && !u2[nv[i][j]]) bv[i][j] = true;
		}
	}
/*	forn(i, xx)
	{
		forn(j, yy)
		{
			cerr << bh[i][j];
		}
		cerr << endl;
	}
	cerr << "---" << endl;
	forn(i, xx)
	{
		forn(j, yy)
		{
			cerr << bv[i][j];
		}
		cerr << endl;
	}
	cerr << "---" << endl;
*/
	int hh = 0, vv = 0;
	forn(i, xx)
	{
		if (xr[i][1] < 0) continue;
		int st = -1;
		forn(j, yy + 1)
		{
			if (bh[i][j])
			{
				if (st < 0) st = j;
			}
			else
			{
				if (st >= 0)
				{
					ah[hh][0] = i;
					ah[hh][1] = st;
					ah[hh][2] = i;
					ah[hh][3] = j - 1;
					hh++;
					st = -1;
				}
			}
		}
	}
	forn(j, yy)
	{
		if (yr[j][1] < 0) continue;
		int st = -1;
		forn(i, xx + 1)
		{
			if (bv[i][j])
			{
				if (st < 0) st = i;
			}
			else
			{
				if (st >= 0)
				{
					av[vv][0] = st;
					av[vv][1] = j;
					av[vv][2] = i - 1;
					av[vv][3] = j;
					vv++;
					st = -1;
				}
			}
		}
	}

	printf("%d\n", vv);
	forn(i, vv)
	{
		forn(j, 2)
		{
			printf("%d %d%c", xs[av[i][j * 2]], ys[av[i][j * 2 + 1]], " \n"[j == 1]);
		}
	}
	printf("%d\n", hh);
	forn(i, hh)
	{
		forn(j, 2)
		{
			printf("%d %d%c", xs[ah[i][j * 2]], ys[ah[i][j * 2 + 1]], " \n"[j == 1]);
		}
	}
	
	return 0;
}