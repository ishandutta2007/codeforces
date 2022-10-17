#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int N = 100005;
int n, q;
string opt;
ll ans, depp[N];
vector<P> g[N];
set<int> s;
int sz[N], son[N], top[N], fa[N], dep[N], dfn, id[N], mp[N];

void dfs1(int u) {
	sz[u] = 1;
	for(auto p : g[u]) {
		int v = p.first;
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		depp[v] = depp[u] + p.second;
		dfs1(v);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	id[u] = ++dfn;
	mp[dfn] = u;
	if(son[u]) dfs2(son[u], tp);
	for(auto p : g[u]) {
		int v = p.first;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
 
inline ll dis(int u, int v) {
	ll res = depp[u] + depp[v];
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return res - 2 * min(depp[u], depp[v]);
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		g[u].emplace_back(P(v, w));
		g[v].emplace_back(P(u, w));
	}
	dfs1(1), dfs2(1, 1);
	cin >> q;
	for(int i = 1, u, x; i <= q; ++i) {
		cin >> opt;
		if(opt[0] == '?') {
			cout << ans / 2 << endl;
		} else {
			cin >> u, x = id[u];
			if(opt[0] == '+') s.insert(x);
			auto it = s.find(x), tmp = it; 
			int lst, nxt; ll delta;
			lst = it == s.begin() ? mp[*s.rbegin()] : mp[*--(tmp = it)];
			nxt = x == *s.rbegin() ? mp[*s.begin()] : mp[*++(tmp = it)];
			delta = dis(u, lst) + dis(u, nxt) - dis(lst, nxt);
			ans += delta * (opt[0] == '+' ? 1 : -1);
			if(opt[0] == '-') s.erase(it); 
		}
	} 
	return 0;
}