#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int tot = 1, np = 1, ch[N][26], fa[N], dep[N];
vector<int> g[N];
int extend(int x) {
	#define q ch[p][x]
	int p = np;
	dep[np = ++tot] = dep[p] + 1;
	for (; p && !q; q = np, p = fa[p]);
	if (!p) fa[np] = 1;
	else if (dep[q] == dep[p] + 1) fa[np] = q;
	else {
		int nq = ++tot;
		dep[nq] = dep[p] + 1;
		memcpy(ch[nq], ch[q], 104);
		fa[nq] = fa[q], fa[np] = fa[q] = nq;
		for (int Q = q; p && q == Q; q = nq, p = fa[p]);
	}
	return np;
	#undef q
}
char s[N];
int n, q, L[N], R[N], edp[N];
int siz[N], son[N], top[N], val[N], cnt;
pair<int, int> pot[N];
long long ans[N];
vector<int> mdf[N][2], qry[N][2];
void dfs1(int u) {
	siz[u] = 1;
	for (auto v : g[u]) {
		dfs1(v), siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void dfs2(int u, int t) {
	top[u] = t;
	for (auto v : g[u]) dfs2(v, v == son[u] ? t : v);
}
struct BIT {
	long long c[N];
	inline void modify(int p, int x) { for (; p <= n + 1; p += p & -p) c[p] += x; }
	inline long long query(int p) { long long res = 0; for (; p; p -= p & -p) res += c[p]; return res; }
	inline long long query(int l, int r) { return query(r) - query(l - 1); }
	inline void clear(int p) { for (; p <= n + 1; p += p & -p) c[p] = 0; }
} t1, t2, t3, t4, t5, t6;
vector<int> qry1[N], qry2[N];
void solve_down() {
	for (int p = 1; p <= cnt; ++p) {
		int u, t; tie(u, t) = pot[p];
		for (auto i : qry[u][t]) {
			int pos = lower_bound(val + 1, val + p, R[i] - L[i] + 1) - val;
			if (pos <= p - 1) {
				qry1[p - 1].emplace_back(i);
				qry1[pos - 1].emplace_back(-i);
			}
			if (--pos) qry2[pos].emplace_back(i);
		}
	}
	for (int p = 1; p <= cnt; ++p) {
		int u, t; tie(u, t) = pot[p];
		for (auto i : mdf[u][t]) {
			t1.modify(i, 1), t2.modify(i, i + 1);
			int pos = max(1, i + 1 - val[p]);
			t3.modify(pos, i + 1), t4.modify(pos, 1);
			t5.modify(pos, val[p]), t6.modify(i, val[p]);
		}
		for (auto i : qry1[p]) {
			int j = abs(i);
			long long res = t2.query(R[j]) - t1.query(R[j]) * L[j];
			ans[j] += i > 0 ? res : -res;
		} 
		for (auto i : qry2[p]) {
			int l = L[i], r = R[i];
			ans[i] += t3.query(l) - t4.query(l) * l + t5.query(l + 1, n + 1);
			ans[i] -= t6.query(r + 1, n + 1);
		}
		qry1[p].clear(), qry2[p].clear();
	}
	for (int p = 1; p <= cnt; ++p) {
		int u, t; tie(u, t) = pot[p];
		for (auto i : mdf[u][t]) {
			t1.clear(i), t2.clear(i);
			int pos = max(1, i + 1 - val[p]);
			t3.clear(pos), t4.clear(pos);
			t5.clear(pos), t6.clear(i);
		}
	}
}
void solve_up() {
	for (int p = cnt; p; --p) {
		int u, t; tie(u, t) = pot[p];
		for (auto i : qry[u][t]) {
			int l = L[i], r = R[i];
			if (val[p] >= r - l + 1) {
				ans[i] += t2.query(r) - t1.query(r) * l;
			} else {
				int pos = min(n + 1, l + val[p]);
				ans[i] += t3.query(pos) - t4.query(pos) * l;
				ans[i] += t4.query(pos + 1, n + 1) * val[p];
				ans[i] -= t1.query(r + 1, n + 1) * val[p];
			}
		}
		for (auto i : mdf[u][t]) {
			t1.modify(i, 1), t2.modify(i, i + 1);
			t3.modify(i + 1, i + 1), t4.modify(i + 1, 1);
		}
	}
	for (int p = cnt; p; --p) {
		int u, t; tie(u, t) = pot[p];
		for (auto i : mdf[u][t]) {
			t1.clear(i), t2.clear(i);
			t3.clear(i + 1), t4.clear(i + 1);
		}
	}
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	for (int i = 1; i <= n; ++i) edp[i] = extend(s[i] - 'a');
	for (int i = 2; i <= tot; ++i) g[fa[i]].emplace_back(i);
	dfs1(1), dfs2(1, 1);
	for (int i = 1; i <= n; ++i) {
		int u = edp[i]; 
		mdf[u][0].emplace_back(i);
		for (int l = top[u], u = fa[l]; u; l = top[u], u = fa[l]) mdf[l][1].emplace_back(i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &R[i], &L[i]);
		L[i] = n - L[i] + 1, R[i] = n - R[i] + 1;
		ans[i] = 1ll * (L[i] - 1) * (L[i] - 2) / 2 + min(R[i] - L[i] + 1, dep[edp[R[i]]]);
		int u = edp[R[i]];
		qry[u][0].emplace_back(i);
		for (int l = top[u], u = fa[l]; u; l = top[u], u = fa[l]) qry[l][1].emplace_back(i);
	}
	for (int u = 1; u <= tot; ++u) {
		if (top[u] != u) continue;
		for (int v = u; v; v = son[v]) {
			pot[++cnt] = {v, 0}, val[cnt] = dep[v];
			for (auto x : g[v])	if (x != son[v]) 
				pot[++cnt] = {x, 1}, val[cnt] = dep[v];		
		}
	 	solve_down(), solve_up(), cnt = 0;
	}
	for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}