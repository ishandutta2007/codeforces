#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define mt make_tuple
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define rank hurank
#define prev huprev
#define link hulink
#define hash huhash
#define y0 yy0
#define y1 yy1
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (false) cerr
#endif

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;

const int N = 1010;
const int M = int(3e4) + 100;

int cur, edges;
bool used[N];
int pv[N], pe[N], tin[N], tout[N], first[N], d[N], best[N], prev[N], rank[N];
vi g[N];
int a[M], b[M], c[M];
bool is_bridge[M], del[M];
int go[2 * M], num[2 * M], next[2 * M];

void dfs1(int v) {
	used[v] = true;
	for (int e : g[v]) {
		int u = a[e] ^ b[e] ^ v;
		if (!used[u]) {
			pv[u] = v;
			pe[u] = e;
			dfs1(u);
		}
	}
}

void dfs2(int v, int pe) {
	used[v] = true;
	tin[v] = tout[v] = cur++;
	for (int e : g[v]) {
		if (del[e] || e == pe) {
			continue;
		}
		int u = a[e] ^ b[e] ^ v;
		if (!used[u]) {
			dfs2(u, e);
			tout[v] = min(tout[v], tout[u]);
			if (tout[u] > tin[v]) {
				is_bridge[e] = true;
			}
		}
		else {
			tout[v] = min(tout[v], tin[u]);
		}
	}
}

int get(int a) {
	if (prev[a] != a) {
		prev[a] = get(prev[a]);
	}
	return prev[a];
}

inline void merge(int a, int b) {
	if (rank[a] < rank[b]) {
		swap(a, b);
	}
	prev[b] = a;
	if (rank[a] == rank[b]) {
		++rank[a];
	}
}

inline void add(int a, int b, int c) {
	go[edges] = b;
	num[edges] = c;
	next[edges] = first[a];
	first[a] = edges++;
}

void dfs3(int v, pii p) {
	d[v] = p.fs;
	best[v] = p.sc;
	used[v] = true;
	for (int e = first[v]; e != -1; e = next[e]) {
		if (!used[go[e]]) {
			dfs3(go[e], min(p, mp(c[num[e]], num[e])));
		}
	}
}

int main() {
#define TASK "B"
#ifdef LOCAL42
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s;
	--t;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", a + i, b + i, c + i);
		--a[i];
		--b[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}
	dfs1(s);
	if (!used[t]) {
		printf("0\n0\n");
		return 0;
	}
	int ans = 2 * inf + 100;
	vi lst;
	for (int i = t; i != s; i = pv[i]) {
		for (int j = 0; j < n; ++j) {
			used[j] = false;
		}
		for (int j = 0; j < m; ++j) {
			is_bridge[j] = false;
			del[j] = false;
		}
		cur = 0;
		del[pe[i]] = true;
		dfs2(s, -1);
		for (int j = 0; j < n; ++j) {
			prev[j] = j;
			rank[j] = 1;
		}
		for (int j = 0; j < m; ++j) {
			if (del[j] || is_bridge[j]) {
				continue;
			}
			int x = get(a[j]), y = get(b[j]);
			if (x != y) {
				merge(x, y);
			}
		}
		del[pe[i]] = false;
		if (get(s) == get(t)) {
			continue;
		}
		for (int j = 0; j < n; ++j) {
			first[j] = -1;
			used[j] = false;
			d[j] = inf + 100;
		}
		edges = 0;
		for (int j = 0; j < m; ++j) {
			if (is_bridge[j]) {
				int x = get(a[j]), y = get(b[j]);
				assert(x != y);
				add(x, y, j);
				add(y, x, j);
			}
		}
		dfs3(get(s), mp(inf + 100, -1));
		if (d[get(t)] == inf + 100) {
			if (c[pe[i]] < ans) {
				ans = c[pe[i]];
				lst = { pe[i] };
			}
		}
		else {
			if (c[pe[i]] + d[get(t)] < ans) {
				ans = c[pe[i]] + d[get(t)];
				lst = { pe[i], best[get(t)] };
			}
		}
	}
	if (ans > 2 * inf) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	cout << sz(lst) << endl;
	for (int num : lst) {
		cout << num + 1 << " ";
	}
	cout << endl;
	return 0;
}