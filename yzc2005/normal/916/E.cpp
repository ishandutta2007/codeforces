#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(u) for(int i = head[u], v = to[i]; i; i = nxt[i], v = to[i]) 
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 1e5 + 5, K = 20; 
int n, q, op, u, v, x, rt = 1, a[N], dfn, s[N], t[N], b[N], dep[N], fa[N][K], Log[N];
int to[N << 1], nxt[N << 1], head[N], cnt;

struct SMT {
	int l[N << 2], r[N << 2];
	ll val[N << 2], lzy[N << 2];
	#define mid (l[p] + r[p] >> 1)
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	
	inline void pushup(int p) {
		val[p] = val[ls] + val[rs];
	}
	
	inline void tag(int p, ll v) {
		val[p] += (r[p] - l[p] + 1) * v;
		lzy[p] += v;
	}
	
	inline void pushdown(int p) {
		if(lzy[p] != 0) {
			tag(ls, lzy[p]);
			tag(rs, lzy[p]);
			lzy[p] = 0;
		}
	}
	
	void build(int p, int L, int R) {
		l[p] = L, r[p] = R;
		if(l[p] == r[p]) return val[p] = b[L], void();
		build(ls, L, mid), build(rs, mid + 1, R);
		pushup(p);
	}
	
	void modify(int p, int L, int R, ll v) {
		if(L <= l[p] && r[p] <= R) return tag(p, v);
		pushdown(p);
		if(mid >= L) modify(ls, L, R, v);
		if(mid < R) modify(rs, L, R, v);
		pushup(p);
	}
	
	ll query(int p, int L, int R) {
		if(L <= l[p] && r[p] <= R) return val[p];
		ll res = 0; pushdown(p);
		if(mid >= L) res = query(ls, L, R);
		if(mid < R) res += query(rs, L, R);
		return res;
	}
} smt;

inline void add(int u, int v) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt; 
}

void dfs(int u) {
	s[u] = ++dfn;
	b[s[u]] = a[u];
	go(u) {
		if(v == fa[u][0]) continue;
		dep[v] = dep[u] + 1, fa[v][0] = u;
		fu(k, 1, Log[dep[v]]) fa[v][k] = fa[fa[v][k - 1]][k - 1];
		dfs(v);
	}
	t[u] = dfn;
}

inline int getfa(int u, int d) {
	fu(k, 0, Log[d]) if(d >> k & 1) u = fa[u][k];
	return u;
}

inline int getlca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	u = getfa(u, dep[u] - dep[v]);
	if(u == v) return u;
	fd(k, Log[dep[u]], 0) if(fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
	return fa[u][0];
}

inline bool in(int v, int u) {
	return s[u] <= s[v] && s[v] <= t[u];
}

inline void deal() {
	int lca = getlca(u, v);
	u = getlca(u, rt), v = getlca(v, rt);
	if(lca == rt || (in(u, rt) && !in(v, rt)) || (!in(u, rt) && in(v, rt))) return smt.tag(1, x);
	if(in(lca, rt)) return smt.modify(1, s[lca], t[lca], x);
	if(u == v) {
		if(lca == u) {
			u = getfa(rt, dep[rt] - dep[u] - 1);
			smt.tag(1, x), smt.modify(1, s[u], t[u], -x);
		}
		else smt.modify(1, s[lca], t[lca], x);
		return;
	}
	if(dep[u] < dep[v]) swap(u, v);
	u = getfa(rt, dep[rt] - dep[u] - 1);
	smt.tag(1, x), smt.modify(1, s[u], t[u], -x);
}

inline ll query() {
	if(u == rt) return smt.val[1];
	if(in(u, rt) || dep[u] >= dep[rt] || getfa(rt, dep[rt] - dep[u]) != u) return smt.query(1, s[u], t[u]);
	u = getfa(rt, dep[rt] - dep[u] - 1); return smt.val[1] - smt.query(1, s[u], t[u]);
}

int main() {
	rd(n), rd(q);
	fu(i, 1, n) rd(a[i]);
	fu(i, 1, n - 1) rd(u), rd(v), add(u, v), add(v, u);
	fu(i, 2, n) Log[i] = Log[i >> 1] + 1; dfs(1);
	smt.build(1, 1, n);
	while(q--) {
		rd(op);
		if(op == 1) rd(rt);
		if(op == 2) rd(u), rd(v), rd(x), deal();
		if(op == 3) rd(u), printf("%lld\n", query());
	}
	return 0;
}