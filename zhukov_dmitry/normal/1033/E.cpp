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

//#ifndef ROOM_311
#define cerr if (0) cerr
//#endif

int n, m;
bool a[666][666];
bool u[666];
bool u2[666];
int c[666];
int g[666][666];
int total = 0;

int query(const VI &b)
{
	if (b.sz < 2)
	{
#ifdef ROOM_311
		printf("? %d\n", (int)b.sz);
		forn(i, b.sz)
		{
			printf("%d%c", b[i] + 1, " \n"[i == (int)b.sz - 1]);
		}
		printf("k=%d\n", 0);
#endif
		return 0;
	}
	total++;
	assert(total <= 20000);
	printf("? %d\n", (int)b.sz);
	forn(i, b.sz)
	{
		printf("%d%c", b[i] + 1, " \n"[i == (int)b.sz - 1]);
	}
	fflush(stdout);
	int k = 0;
#ifdef ROOM_311
	forn(i, b.sz)
	{
		forn(j, i)
		{
			if (a[b[i]][b[j]]) k++;
		}
	}
	printf("k=%d\n", k);
#else
	scanf("%d", &k);
#endif
	return k;
}

bool find_edge(int &x, int &y)
{
	VI v;
	v.reserve(n);
	forn(i, n)
	{
		if (!u[i]) v.pb(i);
	}
	int m1 = query(v);
	if (!m1) return false;
	while (v.sz > 2)
	{
		int t = (v.sz + 1) / 2;
		VI l, r;
		l.reserve(t);
		r.reserve(t);
		clr(u2);
		forn(i, t)
		{
			int x;
			do
			{
				x = rand() % v.sz;
			}
			while (u2[x]);
			u2[x] = true;
			l.pb(v[x]);
		}
		forn(i, v.sz)
		{
			if (u2[i]) continue;
			r.pb(v[i]);
		}
		int lm = query(l);
		if (lm > 0)
		{
			v = l;
			continue;
		}
		int rm = query(r);
		if (rm > 0)
		{
			v = r;
			continue;
		}
	}
	x = v[0];
	y = v[1];
	return true;
}

int find_edge3(int q, VI v)
{
	cerr << "find_edge3 " << q + 1 << endl;
	while ((int)v.sz > 1)
	{
		int t = (v.sz + 1) / 2;
		VI l, r;
		l.reserve(t);
		r.reserve(t);
		clr(u2);
		forn(i, t)
		{
			int x;
			do
			{
				x = rand() % (v.sz);
			}
			while (u2[x]);
			u2[x] = true;
			l.pb(v[x]);
		}
		For(i, 0, v.sz - 1)
		{
			if (u2[i]) continue;
			r.pb(v[i]);
		}
		l.pb(q);
		int lm = query(l);
		if (lm > 0)
		{
			l.pop_back();
			v = l;
			continue;
		}
		else
		{
			v = r;
			continue;
		}
	}
//	cerr << "+:  " << q + 1 << " " << v[0] + 1 << endl;
	g[q][v[0]] = true;
	g[v[0]][q] = true;
	return v[0];
}

bool dfs(int x, int y, VI &path)
{
//	cerr << x << endl;
	if (x == y)
	{
		path.pb(x);
		return true;
	}
	u2[x] = true;
	forn(i, n)
	{
		if (u2[i]) continue;
		if (g[x][i])
		{
			if (dfs(i, y, path))
			{
				path.pb(x);
				return true;
			}
		}
	}
	return false;
}

bool find_edge2(VI &lv, VI &rv)
{
	cerr << "lv:";
	for(int i : lv) cerr << " " << i + 1;
	cerr << endl;
	cerr << "rv:";
	for(int i : rv) cerr << " " << i + 1;
	cerr << endl;
	VI v;
	v.reserve(n);
	for (int x : lv)
	{
		v.pb(x);
	}
	for (int x : rv)
	{
		v.pb(x);
	}
	int v0 = v.sz;
	int ecnt = query(v);
	VI v2;
	forn(i, n)
	{
		if (!u[i])
		{
			v.pb(i);
			v2.pb(i);
		}
	}
	int m1 = query(v) - query(v2);
	if (m1 == ecnt) return false;
	while ((int)v.sz > v0 + 1)
	{
		int t = (v.sz - v0 + 1) / 2;
		VI l, r, l2/*, r2*/;
		l = v;
		l.resize(v0);
		r = v;
		r.resize(v0);
		clr(u2);
		forn(i, t)
		{
			int x;
			do
			{
				x = v0 + rand() % (v.sz - v0);
			}
			while (u2[x]);
			u2[x] = true;
			l.pb(v[x]);
			l2.pb(v[x]);
		}
		For(i, v0, v.sz - 1)
		{
			if (u2[i]) continue;
			r.pb(v[i]);
//			r2.pb(v[i]);
		}
	cerr << "l:";
	for(int i : l) cerr << " " << i + 1;
	cerr << endl;
	cerr << "r:";
	for(int i : r) cerr << " " << i + 1;
	cerr << endl;
		int lm = query(l) - query(l2);
		if (lm > ecnt)
		{
			v = l;
			continue;
		}
		else
		{
			v = r;
			continue;
		}
//		int rm = query(r);
//		if (rm > 0)
//		{
//			v = r;
//			continue;
//		}
	}
	cerr << "--" << endl;
	u[v[v0]] = true;
	VI l = lv;
	l.pb(v[v0]);
	if (!query(l))
	{
		c[v[v0]] = 0;
		cerr << "c[" << v[v0] + 1 << "]=0" << endl;
		lv.pb(v[v0]);
		find_edge3(v[v0], rv);
		return true;
	}
	VI r = rv;
	r.pb(v[v0]);
	if (!query(r))
	{
		c[v[v0]] = 1;
		cerr << "c[" << v[v0] + 1 << "]=1" << endl;
		rv.pb(v[v0]);
		find_edge3(v[v0], lv);
		return true;
	}

	//
	int x1 = find_edge3(v[v0], lv);
	int x2 = find_edge3(v[v0], rv);
	VI path;
	clr(u2);
	u2[v[v0]] = true;
/*	forn(i, n)
	{
		forn(j, n)
		{
			cerr << g[i][j] << " ";
		}
		cerr << endl;
	}
	cerr << "v[v0] = " << v[v0] + 1 << endl;
	cerr << "x1 = " << x1 + 1 << endl;
	cerr << "x2 = " << x2 + 1 << endl;*/
	if (!dfs(x1, x2, path))
	{
		cerr << "Botwa !!!" << endl;
		exit(239);
	}
	path.pb(v[v0]);
	printf("N %d\n", (int)path.sz);
	forn(i, path.sz)
	{
		printf("%d%c", path[i] + 1, " \n"[i == (int)path.sz - 1]);
	}
	fflush(stdout);
#ifdef ROOM_311
	cerr << "total=" << total << endl;
#endif
	exit(0);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	clr(a);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x][y] = true;
		a[y][x] = true;
	}

/*	clr(a);
	n = 599;
	forn(i, n)
	{
		a[i][(i + 1) % n] = a[(i + 1) % n][i] = true;
	}
*/
#else
	scanf("%d", &n);
#endif
/*	VI all;
	forn(i, n)
	{
		all.pb(i);
	}
	m = query(all);*/
	memset(c, 0xff, sizeof(c));
	memset(g, 0, sizeof(g));
	clr(u);
	int x, y;
	while (find_edge(x, y))
	{
		cerr << "+ : " << x + 1 << " " << y + 1 << endl;
		g[x][y] = 1;
		g[y][x] = 1;
		c[x] = 0;
		c[y] = 1;
		u[x] = true;
		u[y] = true;
		VI lv(1, x), rv(1, y);
		while (find_edge2(lv, rv))
		{
		}
	}

	VI l, r;
	forn(i, n)
	{
		if (c[i] < 0) c[i] = 0;
		if (!c[i]) l.pb(i);
		else r.pb(i);
	}
	printf("Y %d\n", (int)l.sz);
	forn(i, l.sz)
	{
		printf("%d%c", l[i] + 1, " \n"[i == (int)l.sz - 1]);
	}
//	assert(!query(l));
//	assert(!query(r));
#ifdef ROOM_311
	cerr << "total=" << total << endl;
#endif
	
	return 0;
}