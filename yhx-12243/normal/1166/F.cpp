#include <bits/stdc++.h>

typedef std::set <int> set;
typedef std::map <int, int> map;
const int N = 100054;

int V, E, q;
int p[N];
set adj[N];
map ep[N];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline bool test(int x, int y, bool un = false) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	return un && (p[x] = y, false);
}

void merge(set &dest, set &src) {
	if (dest.size() < src.size()) dest.swap(src);
	for (int x : src) dest.emplace(x); src.clear();
}

void link(int u, int v, int w) {
	int x; map::iterator it; bool ret;
	adj[ancestor(u)].emplace(v), std::tie(it, ret) = ep[u].emplace(w, v);
	if (!(ret || test(x = ancestor(it->second), v = ancestor(v), true)))
		merge(adj[v], adj[x]);
}

int main() {
	int i, u, v, w; char op[4];
	scanf("%d%d%*d%d", &V, &E, &q);
	std::iota(p, p + (V + 1), 0);
	for (i = 0; i < E; ++i) scanf("%d%d%d", &u, &v, &w), link(u, v, w), link(v, u, w);
	for (; q; --q)
		if (scanf("%s", op), *op == 43)
			scanf("%d%d%d", &u, &v, &w), link(u, v, w), link(v, u, w);
		else
			scanf("%d%d", &u, &v),
			puts(test(u, v) || adj[ancestor(u)].count(v) ? "Yes" : "No");
	return 0;
}