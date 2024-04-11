#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "d"
#define H 18
#define ROOT 0

vector <int> g[100001];
int par[100001][H];
int in[100001];
int ver[100001];
int out[100001];
int h[100001];
int timer;
ll res[100001];
int mid[100001];
vector <int> u_query[100001];
vector <int> v_query[100001];
int n;

void precalc(int u, int prev = ROOT) {
	par[u][0] = prev;
	h[u] = h[prev] + 1;
	for (int i = 1; i < H; ++i)
		par[u][i] = par[par[u][i - 1]][i - 1];
	ver[timer] = u;
	in[u] = timer++;
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		if (v == prev)
			continue;
		precalc(v, u);
	}
	out[u] = timer;
}

char is_prev(int u, int v) {
	return in[u] <= in[v] && out[v] <= out[u];
}

inline int lca(int u, int v) {
	for (int i = H - 1; i >= 0; --i)
		if (!is_prev(par[u][i], v))
			u = par[u][i];
	if (!is_prev(u, v))
		u = par[u][0];
	return u;
}

inline int get_par(int u, int ch) {
	for (int i = H - 1; i >= 0; --i)
		if (h[par[u][i]] >= ch)
			u = par[u][i];
	return u;
}

#define base 131072
ll t[base * 2];
ll upd[base * 2];

inline void push(int u) {
	t[u * 2] += upd[u];
	upd[u * 2] += upd[u];
	t[u * 2 + 1] += upd[u];
	upd[u * 2 + 1] += upd[u];
	upd[u] = 0;
}

inline void update(int u) {
	t[u] = max(t[u * 2], t[u * 2 + 1]);
}

void put(int l, int r, ll delta, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r) {
		t[v] += delta;
		upd[v] += delta;
		return;
	}
	if (cr <= l || r <= cl)
		return;
	push(v);
	int cc = (cl + cr) / 2;
	put(l, r, delta, v * 2, cl, cc);
	put(l, r, delta, v * 2 + 1, cc, cr);
	update(v);
}

ll get(int l, int r, int v = 1, int cl = 0, int cr = base) {
	if (l <= cl && cr <= r)
		return t[v];
	if (cr <= l || r <= cl)
		return 0;
	push(v);
	int cc = (cl + cr) / 2;
	return max(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

void dfs(int u) {
	for (int i = 0; i < sz(u_query[u]); ++i) {
		int id = u_query[u][i];
		res[id] = max(res[id], get(0, in[mid[id]]));
		res[id] = max(res[id], get(out[mid[id]], n));
	}
	for (int i = 0; i < sz(v_query[u]); ++i) {
		int id = v_query[u][i];
		res[id] = max(res[id], get(in[mid[id]], out[mid[id]]));
	}
	for (int i = 0; i < (int) g[u].size(); ++i) {
		int v = g[u][i];
		if (h[v] < h[u])
			continue;
		assert(h[v] == h[u] + 1);
		put(0, n, 1);
		put(in[v], out[v], -2);
		dfs(v);
		put(in[v], out[v], 2);
		put(0, n, -1);
	}
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	h[ROOT] = -1;
	precalc(ROOT);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int w = lca(u, v);
		int hu = h[u] - h[w];
		int hv = h[v] - h[w];
		if (hu > hv) {
			swap(u, v);
			swap(hu, hv);
		}
		int dist = (hu + hv) / 2;
		if (hu == hv)
			--dist;
		mid[i] = get_par(v, h[v] - dist);
		//~ cerr << u << ' ' << v << ' ' << mid[i] << '\n';
		u_query[u].pb(i);
		v_query[v].pb(i);
	}
	for (int i = 0; i < n; ++i)
		t[i + base] = h[ver[i]];
	for (int i = n; i < base; ++i)
		t[i + base] = 0;
	for (int i = base - 1; i > 0; --i)
		update(i);
	dfs(ROOT);
	for (int i = 0; i < m; ++i)
		cout << res[i] << '\n';
}