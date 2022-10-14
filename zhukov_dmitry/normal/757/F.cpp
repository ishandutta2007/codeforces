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
typedef pair < i64, int > PLI;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

const i64 INF = 0x3f3f3f3f3f3f3f3f;

struct tv
{
	int node, weight;
	bool s = false;

	tv(int x, int y) : node(x), weight(y) {}
};

int n, m;
vector < tv > a[302400];
i64 d[302400];
bool u[302400];
int p[302400];
int u2[302400];
int c[302400];
int tt = 0;
int e[302400];
int c2[302400];

void calc_dist(int s)
{
	memset(d, 0x3f, sizeof(d));
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	clr(u);
	d[s] = 0;
	q.push(mp(d[s], s));
	while (!q.empty())
	{
		PLI tmp = q.top();
		q.pop();
		int v = tmp.second;
		if (u[v]) continue;
		u[v] = true;
		fori(it, a[v])
		{
			int vn = it->node;
			int add = it->weight;
			if (d[vn] > d[v] + add)
			{
				d[vn] = d[v] + add;
				q.push(mp(d[vn], vn));
			}
		}
	}
}

int calc_ans(int s)
{
	int ee = 0;
	tt++;
	int ans = 0;
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	q.push(mp(d[s], s));
	e[ee++] = s;
	c2[s] = c[s];
	while (!q.empty())
	{
		PLI tmp = q.top();
		q.pop();
		int v = tmp.second;
		if (c2[v] != c[v]) continue;
		ans++;
		u[v] = true;
		u2[v] = tt;
		fori(it, a[v])
		{
//			if (!it->s) continue;
			int vn = it->node;
			e[ee++] = vn;
			c2[vn]++;
			if (u2[vn] < tt)
			{
				u2[vn] = tt;
//				cerr << "! " << s << " " << vn << endl;
				q.push(mp(d[vn], vn));
			}
		}
	}
	forn(i, ee)
	{
		c2[e[i]] = 0;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	int s;
	scanf("%d%d%d", &n, &m, &s);
	s--;
	forn(i, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		a[x].pb(tv(y, z));
		a[y].pb(tv(x, z));
	}
	calc_dist(s);
	int k = 0;
	clr(c);
	forn(i, n)
	{
		if (d[i] >= INF) continue;
		if (i != s) p[k++] = i;
		fori(it, a[i])
		{
			if (d[i] + it->weight == d[it->node])
			{
				it->s = true;
				c[it->node]++;
			}
		}
	}
	forn(i, n)
	{
		vector<tv> z;
		z.reserve(a[i].sz);
		fori(it, a[i])
		{
			if (it->s) z.pb(*it);
		}
		a[i].swap(z);
	}
	sort(p, p + k, [] (int const &l, int const &r) { return d[l] < d[r]; } );
	clr(u);
	clr(u2);
	clr(c2);
	int ans = 0;
	forn(i, k)
	{
		int v = p[i];
		if (u[v]) continue;
		int cur = calc_ans(v);
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	
	return 0;
}