#include <bits/stdc++.h>
using namespace std;

const int N = 300005, M = 1000005;
int n, m, q, a[N], b[N];

struct SegmentTree {
	int val[M << 2], lzy[M << 2];
	
	#define mid (l + r >> 1)
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	
	inline void pushup(int p) {
		val[p] = max(val[ls], val[rs]);
	}
	
	inline void tag(int p, int v) {
		val[p] += v, lzy[p] += v;
	} 
	inline void pushdown(int p) {
		if(lzy[p]) {
			tag(ls, lzy[p]), tag(rs, lzy[p]);
			lzy[p] = 0;
		}
	}
	void add(int p, int l, int r, int ql, int qr, int v) {
		if(ql <= l && r <= qr) return tag(p, v);
		pushdown(p);
		if(mid >= ql) add(ls, l, mid, ql, qr, v);
		if(mid < qr) add(rs, mid + 1, r, ql, qr, v);
		pushup(p);
	}
	int query(int p = 1, int l = 1, int r = 1e6) {
		if(l == r) return l;
		pushdown(p);
		if(val[rs] > 0) return query(rs, mid + 1, r);
		else return query(ls, l, mid);
	}
} smt;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), smt.add(1, 1, 1e6, 1, a[i], 1);
	for(int i = 1; i <= m; ++i) scanf("%d", &b[i]), smt.add(1, 1, 1e6, 1, b[i], -1);
	scanf("%d", &q);
	for(int i = 1, op, p, x; i <= q; ++i) {
		scanf("%d%d%d", &op, &p, &x);
		if(op & 1) {
			smt.add(1, 1, 1e6, 1, a[p], -1);
			smt.add(1, 1, 1e6, 1, a[p] = x, 1);
		} else {
			smt.add(1, 1, 1e6, 1, b[p], 1);
			smt.add(1, 1, 1e6, 1, b[p] = x, -1);
		}
		if(smt.val[1] <= 0) puts("-1");
		else printf("%d\n", smt.query());
	}
	return 0;
}