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

#define x first
#define y second

const int LOG = 18;

struct hasher_t {
	size_t operator () (PII p) const
	{
		return (p.x << 20) ^ p.y;
	}
};

int n, m, k, nn;
vector<PII> a[102400];
VI g[202400];
int e[502400][2];
int pa[502400];
int num[502400];
VI ec[502400];
bool u[502400];
int up[LOG][202400];
int h[202400];
unordered_set<PII, hasher_t> ue;
unordered_map<PII, int, hasher_t> ne;
VI cv;

inline int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

inline void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rand() & 1) swap(x, y);
	pa[x] = y;
}

//size_t total = 0;
/*
void check3(int x, int y, int z0)
{
	if (x < y) return;
	if (a[x].sz > a[y].sz) swap(x, y);
	if (a[x].sz * 4 < a[y].sz)
	{
		for (auto p : a[x])
		{
			int z = p.x;
			auto it = lower_bound(all(a[y]), mp(z, -1));
			if (it != a[y].end() && it->x == z)
			{
				unite(p.y, it->y);
				unite(p.y, z0);
			}
		}
	}
	else
	{
		size_t iy = 0;
		for (size_t ix = 0; ix < a[x].sz; ++ix)
		{
			auto p = a[x][ix];
			int z = p.x;
			while (iy < a[y].sz && a[y][iy].x < z) ++iy;
			++total;
			if (iy < a[y].sz && a[y][iy].x == z)
			{
				unite(p.y, a[y][iy].y);
				unite(p.y, z0);
			}
		}
	}
}
*/
void dfs0(int ee)
{
	u[ee] = true;
	int x = e[ee][0];
	int y = e[ee][1];
	if (x > y) swap(x, y);
	if (ue.count(mp(x, y))) return;
	ue.insert(mp(x, y));
	if (a[x].sz > a[y].sz) swap(x, y);
//	if (a[x].sz * 4 < a[y].sz)
	{
//			++total;
		for (auto p : a[x])
		{
			int z = p.x;
			auto it = lower_bound(all(a[y]), mp(z, -1));
			if (it != a[y].end() && it->x == z)
			{
				unite(p.y, it->y);
				unite(p.y, ee);
				for (int v : cv)
				{
					int xx = v;
					int yy = z;
					if (xx > yy) swap(xx, yy);
					unite(ee, ne[mp(xx, yy)]);
					ue.insert(mp(xx, yy));
				}
				cv.pb(z);
//				dfs0(p);
			}
		}
	}
}

void dfs(int k, int prev, int hh)
{
	h[k] = hh;
	up[0][k] = prev;
	u[k] = true;
	for (int v : g[k])
	{
		if (u[v]) continue;
		dfs(v, k, hh + 1);
	}
}

int go(int x, int y)
{
	if (h[x] < h[y]) swap(x, y);
	int d = h[x] - h[y];
	ford(i, LOG)
	{
		if (d & (1 << i))
		{
			x = up[i][x];
		}
	}
	if (x == y) return x;
	ford(i, LOG)
	{
		if (up[i][x] != -1 && up[i][y] != -1 && up[i][x] != up[i][y])
		{
			x = up[i][x];
			y = up[i][y];
		}
	}
	assert(up[0][x] == up[0][y]);
	return up[0][x];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d%d", &n, &m, &k);
	forn(i, n)
	{
		a[i].reserve(8);
	}
#ifdef ROOM_311
	n = 1000;
	m =	n * (n - 1) / 2;
	int tx = 0, ty = 1;
#endif
	forn(i, m)
	{
		int x, y;
#ifdef ROOM_311
		x = tx;
		y = ty;
		ty++;
		if (ty >= n)
		{
			tx++;
			ty = tx + 1;
		}
#else
		scanf("%d%d", &x, &y);
		x--;
		y--;
#endif
		assert(x >= 0 && x < n);
		assert(y >= 0 && y < n);
		assert(x != y);
		if (x > y) swap(x, y);
		ne[mp(x, y)] = i;
		e[i][0] = x;
		e[i][1] = y;
		a[x].pb(mp(y, i));
		a[y].pb(mp(x, i));
		pa[i] = i;
	}
	forn(i, n)
	{
		sort(all(a[i]));
	}
	clr(u);
	forn(i, n)
	{
		for (auto p : a[i])
		{
			int x = e[p.y][0];
			int y = e[p.y][1];
			if (x > y) swap(x, y);
			if (ue.count(mp(x, y))) continue;
//			if (!u[p.y])
			{
				cv.clear();
				cv.pb(x);
				cv.pb(y);
				dfs0(p.y);
			}
//			int v = p.x;
//			check3(i, v, p.y);
		}
	}
//	cerr << "total = " << total << endl;
//	return 0;
	nn = n;
	forn(i, m)
	{
		if (pa[i] == i)
		{
			num[i] = nn++;
//			cerr << e[i][0] + 1 << " " << e[i][1] + 1 << endl;
		}
	}
	forn(i, m)
	{
		ec[find(i)].pb(i);
	}
//	cerr << "nn=" << nn << endl;
	forn(i, nn)
	{
		g[i].reserve(8);
	}
//	cerr << "!" << endl;
	forn(i, m)
	{
		if (i == pa[i])
		{
			VI w;
			for (auto ee : ec[i])
			{
				w.pb(e[ee][0]);
				w.pb(e[ee][1]);
			}
			sort(all(w));
			w.erase(unique(all(w)), w.end());
			for (int v : w)
			{
//				cerr << v << " " << i << " " << num[i] << endl;
				g[v].pb(num[i]);
				g[num[i]].pb(v);
			}
		}
	}
	memset(up, 0xff, sizeof(up));
	clr(u);
	dfs(0, -1, 0);
	forn(i, LOG - 1)
	{
		forn(j, nn)
		{
			if (up[i][j] >= 0) up[i + 1][j] = up[i][up[i][j]];
		}
	}
	forn(i, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		int z = go(x, y);
		printf("%d\n", (h[x] + h[y] - h[z] * 2) / 2);
	}
	
	return 0;
}