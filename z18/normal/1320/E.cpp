#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, maxm = 4e5;
int n, q, cur, dfn[maxn + 3], dep[maxn + 3], fa[maxn + 3], id[maxn + 3], sz[maxn + 3], ch[maxn + 3];
int ver[maxm + 3], len[maxn + 3], pnt[maxm + 3], st[maxn + 3], top, infe[maxn + 3], vis[maxn + 3];
vector<int> G[maxn + 3], T[maxn + 3];

void work(int u, int f = 0) {
	dfn[u] = ++cur, sz[u] = 1;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == f) continue;
		dep[v] = dep[u] + 1, work(v, u);
		fa[v] = u, sz[u] += sz[v];
		if (sz[v] > sz[ch[u]]) ch[u] = v;
	}
}

void divide(int u, int f = 0, int i = 1) {
	id[u] = i;
	if (ch[u]) divide(ch[u], u, i);
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == f || v == ch[u]) continue;
		divide(v, u, v);
	}
}

int lca(int u, int v) {
	while (id[u] != id[v]) {
		if (dep[id[u]] < dep[id[v]]) swap(u, v);
		u = fa[id[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

bool comp(int i, int j) { return dfn[i] < dfn[j]; }
void clear(int u) { if (vis[u] != cur) { vis[u] = cur, vector<int>().swap(T[u]), infe[u] = 0; } }
void add(int u, int v) { clear(u), clear(v), T[u].push_back(v), T[v].push_back(u); }
int calc(int u, int v) { return dep[u] - dep[v] < 0 ? dep[v] - dep[u] : dep[u] - dep[v]; }

void insert(int u) {
	int x = lca(u, st[top]);
	while (top >= 2 && dep[st[top - 1]] >= dep[x]) add(st[top], st[top - 1]), top--;
	if (st[top] != x) add(st[top], x), st[top] = x;
	if (st[top] != u) st[++top] = u;
}

struct node {
	int x, ti, id, dist;
	node(int _x = 0, int t = 0, int i = 0, int d = 0) { x = _x, ti = t, id = i, dist = d; }
	friend bool operator < (const node &a, const node &b) {
		return a.ti == b.ti ? a.id > b.id : a.ti > b.ti;
	}
};

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	work(1);
	divide(1);
	scanf("%d", &q);
	cur = 0;
	for (int k, m; q --> 0; ) {
		scanf("%d %d", &k, &m), cur++;
		for (int i = 1; i <= k; i++) scanf("%d %d", &ver[i], &len[i]), pnt[i] = ver[i];
		for (int i = k + 1; i <= k + m; i++) scanf("%d", &ver[i]), pnt[i] = ver[i];
		sort(pnt + 1, pnt + k + m + 1, comp);
		top = 0, st[++top] = 1, pnt[0] = 1;
		vector<int>().swap(T[1]), infe[1] = 0;
		for (int i = 1; i <= k + m; i++) if (pnt[i] != pnt[i - 1]) insert(pnt[i]);
		for (int i = top; i >= 2; i--) add(st[i], st[i - 1]);
		priority_queue<node> H;
		for (int i = 1; i <= k; i++) H.push(node(ver[i], 0, i, 0));
		while (!H.empty()) {
			node t = H.top(); H.pop();
			if (infe[t.x]) continue;
			infe[t.x] = t.id;
			for (int i = 0, v, w; i < T[t.x].size(); i++) {
				v = T[t.x][i], w = t.dist + calc(t.x, v);
				if (!infe[v]) {
					H.push(node(v, (w + len[t.id] - 1) / len[t.id], t.id, w));
				}
			}
		}
		for (int i = k + 1; i <= k + m; i++) printf("%d%c", infe[ver[i]], " \n"[i == k + m]);
	}
	return 0;
}