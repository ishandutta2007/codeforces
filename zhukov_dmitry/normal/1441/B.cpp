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

const int MAXN = 202400;
const int MAXK = 21;
const int MOD = 998244353;

const i64 INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
VI a[MAXN];
VI b[MAXN];

i64 d[MAXK][MAXN];
bool u[MAXK][MAXN];
pair<int, i64> d2[2][MAXN];
bool u2[2][MAXN];

i64 solve2()
{
	clr(u2);
	memset(d2, 0x3f, sizeof(d2));
	struct ts {
		pair<int, i64> d;
		int k;
		int pos;
		
		ts() = default;
		ts(pair<int, i64> d, int k, int pos) : d(d), k(k), pos(pos) {}
	
		bool operator < (ts r) const
		{
			return d > r.d;
		}
	};
	
	priority_queue<ts, vector<ts>> q;
	forn(i, n)
	{
		if (d[MAXK - 1][i] < INF && uin(d2[0][i], mp(0, d[MAXK - 1][i])))
		{
			q.push(ts(d2[0][i], 0, i));
		}
	}
	
	assert((MAXK - 1) % 2 == 0);
	
	while (!q.empty())
	{
		ts v = q.top();
		q.pop();
		if (u2[v.k][v.pos]) continue;
		u2[v.k][v.pos] = true;
		pair<int, i64> dd = v.d;
//		cerr << v.k << " " << v.pos << " " << dd << endl;
		
		if (v.k & 1)
		{
			for (int vn : b[v.pos])
			{
				if (uin(d2[v.k][vn], mp(dd.first, dd.second + 1)))
				{
					q.push(ts(d2[v.k][vn], v.k, vn));
				}
			}
		}
		else
		{
			for (int vn : a[v.pos])
			{
				if (uin(d2[v.k][vn], mp(dd.first, dd.second + 1)))
				{
					q.push(ts(d2[v.k][vn], v.k, vn));
				}
			}
		}
		if (uin(d2[v.k ^ 1][v.pos], mp(dd.first + 1, dd.second)))
		{
			q.push(ts(d2[v.k ^ 1][v.pos], v.k ^ 1, v.pos));
		}
	}
	pair<int, i64> res = mp(0x3f3f3f3f, INF);
	forn(i, 2)
	{
		uin(res, d2[i][n - 1]);
	}
//	cerr << res.first << " " << res.second << endl;
	i64 ans = res.second % MOD;
	i64 tmp = 1;
	forn(i, MAXK - 1)
	{
		tmp = tmp * 2 % MOD;
	}
	forn(i, res.first)
	{
		ans = (ans + tmp) % MOD;
		tmp = tmp * 2 % MOD;
	}
	return ans % MOD;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		b[y].pb(x);
	}
#ifdef ROOM_311
	int add = 60;
	forn(i, add)
	{
		if (i % 5 < 2)
		{
			a[n - 1 + i].pb(n + i);
			b[n + i].pb(n - 1 + i);
		}
		else
		{
			a[n + i].pb(n - 1 + i);
			b[n - 1 + i].pb(n + i);
		}
	}
	n += add;
	m += add;
#endif
	memset(d, 0x3f, sizeof(d));
	d[0][0] = 0;
	clr(u);
	struct ts {
		i64 d;
		int k, pos;
		
		ts() = default;
		ts(i64 d, int k, int pos) : d(d), k(k), pos(pos) {}
	
		bool operator < (ts r) const
		{
			return d > r.d;
		}
	};
	
	priority_queue<ts, vector<ts>> q;
	q.push(ts(0, 0, 0));
	
	while (!q.empty())
	{
		ts v = q.top();
		q.pop();
		if (u[v.k][v.pos]) continue;
		u[v.k][v.pos] = true;
		i64 dd = d[v.k][v.pos];
//		cerr << v.k << " " << v.pos << " " << dd << endl;
		
		if (v.k & 1)
		{
			for (int vn : b[v.pos])
			{
				if (uin(d[v.k][vn], dd + 1))
				{
					q.push(ts(d[v.k][vn], v.k, vn));
				}
			}
		}
		else
		{
			for (int vn : a[v.pos])
			{
				if (uin(d[v.k][vn], dd + 1))
				{
					q.push(ts(d[v.k][vn], v.k, vn));
				}
			}
		}
		if (v.k + 1 < MAXK)
		{
			if (uin(d[v.k + 1][v.pos], dd + (1LL << v.k)))
			{
				q.push(ts(d[v.k + 1][v.pos], v.k + 1, v.pos));
			}
		}
	}
	
	i64 ans = INF;
	forn(i, MAXK)
	{
		uin(ans, d[i][n - 1]);
	}
	if (ans >= INF)
	{
		ans = solve2();
	}
	
	printf("%d\n", int(ans % MOD));
	
	return 0;
}