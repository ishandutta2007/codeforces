#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, a[N], id[N], dep[N], l0[N], r0[N], l1[N], r1[N], dfn0, dfn1;
int hd[N], to[N << 1], nxt[N << 1], cnt;

struct SegmentTree {
	int val[N << 2];
	void add(int p, int l, int r, int ql, int qr, int v) {
		if(ql <= l && r <= qr) return val[p] += v, void();
		int mid = l + r >> 1;
		if(mid >= ql) add(p << 1, l, mid, ql, qr, v);
		if(mid < qr) add(p << 1 | 1, mid + 1, r, ql, qr, v);
	}
	int query(int p, int l, int r, int pos) {
		if(l == r) return val[p];
		int mid = l + r >> 1;
		if(mid >= pos) return val[p] + query(p << 1, l, mid, pos);
		else return val[p] + query(p << 1 | 1, mid + 1, r, pos);
	}	
} T0, T1;

void dfs(int u, int fa) {
	l0[u] = dfn0 + 1, l1[u] = dfn1 + 1; 
	(dep[u] & 1) ? ++dfn1 : ++dfn0;
	id[u] = (dep[u] & 1) ? dfn1 : dfn0;
	for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
	r0[u] = dfn0, r1[u] = dfn1;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		to[++cnt] = v, nxt[cnt] = hd[u], hd[u] = cnt;
		to[++cnt] = u, nxt[cnt] = hd[v], hd[v] = cnt;
	}
	dfs(1, 0);
	for(int i = 1, op, u, v; i <= q; ++i) {
		scanf("%d%d", &op, &u);
		if(op & 1) {
			scanf("%d", &v);
			if(dep[u] & 1) {
				T1.add(1, 1, dfn1, l1[u], r1[u], v);
				T0.add(1, 1, dfn0, l0[u], r0[u], -v);
			} else {
				T0.add(1, 1, dfn0, l0[u], r0[u], v);
				T1.add(1, 1, dfn1, l1[u], r1[u], -v);
			}
		} else {
			if(dep[u] & 1) printf("%d\n", a[u] + T1.query(1, 1, dfn1, id[u]));
			else printf("%d\n", a[u] + T0.query(1, 1, dfn0, id[u]));
		}
	}
	return 0;
}