#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fi first
#define se second
using namespace std;

typedef long long ll;
const int maxn = 1.5e5;
int n, m, k, fa[maxn + 3], dep[maxn + 3], sz[maxn + 3], big[maxn + 3], top[maxn + 3];
int cnt, dfn[maxn + 3], rht[maxn + 3], pnt[maxn + 3], a[maxn + 3], b[maxn + 3], c[maxn + 3];
int seq[maxn * 2 + 3], cur, la[maxn + 3], to, st[maxn + 3], sum[maxn + 3], son[maxn + 3], rt;
vector<int> G[maxn + 3], vec[maxn + 3], T[maxn + 3], X[maxn + 3], tmp;

struct bit {
	int n, m, t[maxn + 3], e[maxn + 3];
	bit(int n = 0) {
		this->n = n, m = 0, fill(t + 1, t + n + 1, 0), fill(e + 1, e + n + 1, 0);
	}
	void cl() { m++; }
	void add(int x, int y) {
		for (int i = x; i <= n; i += i & -i) {
			if (e[i] != m) e[i] = m, t[i] = 0;
			t[i] += y;
		}
	}
	int sum(int x) {
		int y = 0;
		for (int i = x; i; i ^= i & -i) {
			y += e[i] == m ? t[i] : 0;
		}
		return y;
	}
} B;

void dfs1(int u, int pa = 0) {
	sz[u] = 1;
	rep(i, 0, G[u].size() - 1) {
		int v = G[u][i];
		if (v == pa) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[big[u]]) big[u] = v;
	}
}

void dfs2(int u, int pa = 0, int t = 1) {
	dfn[u] = rht[u] = ++cnt, pnt[cnt] = u;
	top[u] = t;
	if (big[u]) dfs2(big[u], u, t), rht[u] = rht[big[u]];
	rep(i, 0, G[u].size() - 1) {
		int v = G[u][i];
		if (v == pa || v == big[u]) continue;
		dfs2(v, u, v);
		rht[u] = rht[v];
	}
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

int kth(int u, int k) {
	int g = dep[u] - k;
	while (dep[top[u]] > g) u = fa[top[u]];
	return pnt[dfn[u] - (dep[u] - g)];
}

ll solve1(int u, int pa = 0) {
	ll res = 0;
	rep(i, 0, G[u].size() - 1) {
		int v = G[u][i];
		if (v == pa) continue;
		res += solve1(v, u);
	}
	rep(i, 0, vec[u].size() - 1) {
		int x = vec[u][i];
		res += B.sum(dfn[a[x]]) + B.sum(dfn[b[x]]);
	}
	rep(i, 0, vec[u].size() - 1) {
		int x = vec[u][i];
		if (dep[a[x]] - dep[c[x]] >= k) {
			int u = kth(a[x], dep[a[x]] - dep[c[x]] - k);
			B.add(dfn[u], 1), B.add(rht[u] + 1, -1);
		}
		if (dep[b[x]] - dep[c[x]] >= k) {
			int u = kth(b[x], dep[b[x]] - dep[c[x]] - k);
			B.add(dfn[u], 1), B.add(rht[u] + 1, -1);
		}
	}
	return res;
}

void cl(int u) {
	if (la[u] != cur) la[u] = cur, vector<int>().swap(T[u]), vector<int>().swap(X[u]);
}

void add(int u, int v) {
	cl(u), cl(v), T[u].push_back(v);
}

void insert(int x) {
	int y = lca(x, st[to]);
	while (to > 1 && dep[st[to - 1]] >= dep[y]) add(st[to - 1], st[to]), to--;
	if (st[to] != y) add(y, st[to]), st[to] = y;
	if (x != y) st[++to] = x;
}

void pre(int u) {
	sum[u] = X[u].size(), son[u] = 0;
	rep(i, 0, T[u].size() - 1) {
		int v = T[u][i];
		pre(v), sum[u] += sum[v];
		if (sum[v] >= sum[son[u]]) son[u] = v;
	}
}

void dfs(int u) {
	rep(i, 0, X[u].size() - 1) {
		int x = X[u][i];
		tmp.push_back(x);
	}
	rep(i, 0, T[u].size() - 1) {
		int v = T[u][i];
		dfs(v);
	}
}

ll work(int u) {
	ll res = 0;
	rep(i, 0, T[u].size() - 1) {
		int v = T[u][i];
		if (v == son[u]) continue;
		res += work(v), B.cl();
	}
	int d = max(0, k - (dep[u] - dep[rt]));
	if (son[u]) {
		res += work(son[u]);
		rep(i, 0, T[u].size() - 1) {
			int v = T[u][i];
			if (v == son[u]) continue;
			vector<int>().swap(tmp), dfs(v);
			rep(j, 0, tmp.size() - 1) {
				int x = tmp[j];
				if (dep[x] - dep[rt] >= d) {
					int y = kth(x, dep[x] - dep[rt] - d);
					res += B.sum(rht[y]) - B.sum(dfn[y] - 1);
				}
			}
			rep(j, 0, tmp.size() - 1) {
				int x = tmp[j];
				B.add(dfn[x], 1);
			}
		}
	}
	rep(i, 0, X[u].size() - 1) {
		int x = X[u][i];
		if (dep[x] - dep[rt] >= d) {
			int y = kth(x, dep[x] - dep[rt] - d);
			res += B.sum(rht[y]) - B.sum(dfn[y] - 1);
		}
		B.add(dfn[x], 1);
	}
	return res;
}

ll solve2(int u) {
	++cur, rt = u;
	int k = 0;
	rep(i, 0, vec[u].size() - 1) {
		int x = vec[u][i];
		seq[++k] = dfn[a[x]], seq[++k] = dfn[b[x]];
	}
	sort(seq + 1, seq + k + 1);
	k = unique(seq + 1, seq + k + 1) - (seq + 1);
	to = 0;
	st[++to] = u, cl(u);
	rep(i, 1, k) insert(pnt[seq[i]]);
	per(i, to - 1, 1) add(st[i], st[i + 1]);
	rep(i, 0, vec[u].size() - 1) {
		int x = vec[u][i];
		X[a[x]].push_back(b[x]);
		X[b[x]].push_back(a[x]);
	}
	pre(u);
	ll res = work(u);
	assert(res % 2 == 0);
	B.cl();
	return res / 2;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	rep(i, 1, n - 1) {
		int u, v; scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	rep(i, 1, m) {
		scanf("%d %d", &a[i], &b[i]);
		c[i] = lca(a[i], b[i]);
		vec[c[i]].push_back(i);
	}
	B = bit(n);
	ll ans = solve1(1);
	B.cl();
	rep(i, 1, n) ans += solve2(i);
	printf("%lld\n", ans);
	return 0;
}