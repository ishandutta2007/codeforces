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

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

const int MAXN = 102400;

int n, m, k;
VI a[102400];
map<PII, int> us;
VI b[102400];
int prio[102400][2];
VI g[102400];
int ans[102400];
int pans[102400];
int u[102400];
bool del[102400];
int sub_cnt[MAXN];
int tt = 1;

void go(int x, int y)
{
	if (us.count(mp(x, y))) return;
	us[mp(x, y)] = k;
	b[k].pb(x);
	int x0 = x;
	while (y != x0)
	{
		us[mp(x, y)] = k;
		b[k].pb(y);
		int idx = lower_bound(a[y].begin(), a[y].end(), x) - a[y].begin();
		if (--idx < 0) idx = a[y].sz - 1;
		int yn = a[y][idx];
		x = y;
		y = yn;
	}
	us[mp(x, y)] = k;
	k++;
}

#define check_del(k) \
		if (del[i]) \
		{ \
			if (i1 < (int)g[k].sz - 1) swap(g[k][i1], g[k].back()); \
			g[k].pop_back(); \
			i1--; \
			continue; \
		}

void pre_dfs(int k)
{
	u[k] = tt;
	sub_cnt[k] = 1;
	forn(i1, g[k].sz)
	{
		int i = g[k][i1];
		check_del(k);
		if (u[i] < tt)
		{
			pre_dfs(i);
			sub_cnt[k] += sub_cnt[i];
		}
	}
}

int dfs_split(int k, int total)
{
	u[k] = tt;
	int mj = -1, ma = -1;
	forn(i1, g[k].sz)
	{
		int i = g[k][i1];
		check_del(k);
		if (u[i] < tt)
		{
			if (sub_cnt[i] > ma)
			{
				ma = sub_cnt[i];
				mj = i;
			}
		}
	}
	return (ma * 2 <= total) ? k : dfs_split(mj, total);
}

void calc(int k, int hh)
{
	if (sub_cnt[k] == 1)
	{
		ans[k] = hh;
		return;
	}

	tt++;
	int v = dfs_split(k, sub_cnt[k]);
	ans[v] = hh;
//	cerr << "k = " << k << " " << "v = " << v << endl;
	VI tmp;
	forn(i1, g[v].sz)
	{
		int i = g[v][i1];
		check_del(v);
		tmp.pb(i);
	}
	del[v] = true;
	forn(i1, tmp.sz)
	{
		int i = tmp[i1];
		tt++;
		pre_dfs(i);
	}
	forn(i1, tmp.sz)
	{
		int i = tmp[i1];
		calc(i, hh + 1);
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		int x = i;
		int y = (i + 1) % n;
		a[x].pb(y);
		a[y].pb(x);
	}
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	forn(i, n)
	{
		sort(all(a[i]));
	}
	k = MAXN - 1;
	go(1, 0);
	k = 0;
	forn(i, n)
	{
		fori(it, a[i])
		{
			int x = i;
			int y = *it;
			go(x, y);
//			go(y, x);
		}
	}
	forn(i, k)
	{
		forn(j, b[i].sz)
		{
//			cerr << b[i][j] << " " << b[i][(j + 1) % b[i].sz] << ",  ";
			__typeof(us.begin()) it = us.find(mp(b[i][(j + 1) % b[i].sz], b[i][j]));
			if (it == us.end() || it->second >= MAXN - 1) continue;
			int z = it->second;
			g[i].pb(z);
		}
//		cerr << endl;
	}
/*	cerr << "g: " << endl;
	forn(i, k)
	{
		cerr << i << ": ";
		fori(it, g[i])
		{
			cerr << *it << " ";
		}
		cerr << endl;
	}*/
	clr(u);
	clr(del);
	tt = 1;
	pre_dfs(0);
	calc(0, 1);
	memset(prio, 0xff, sizeof(prio));
	forn(i, k)
	{
		fori(it, b[i])
		{
			int x = *it;
			if (prio[i][0] < x)
			{
				prio[i][1] = prio[i][0];
				prio[i][0] = x;
			}
			else if (prio[i][1] < x) prio[i][1] = x;
		}
	}
	forn(i, k)
	{
		pans[i] = i;
	}
	sort(pans, pans + k, [] (int const &l, int const &r) { return mp(prio[l][0], prio[l][1]) < mp(prio[r][0], prio[r][1]); });
	forn(i, k)
	{
		printf("%d%c", ans[pans[i]], " \n"[i == k - 1]);
	}
	
	return 0;
}