#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;

int n, m, a[N];

struct SegmentTree {
	int l, r;
	ll mx, val;
} t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (t[p].l + t[p].r >> 1)

inline void pushup(int p) {
	t[p].mx = max(t[ls].mx, t[rs].mx);
	t[p].val = t[ls].val + t[rs].val; 
}

void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if(l == r) return t[p].mx = t[p].val = a[l], void();
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(p);
}

void mod(int p, int l, int r, int x) {
	if(t[p].mx < x) return;
	if(t[p].l == t[p].r) return t[p].mx %= x, t[p].val %= x, void();
	if(mid >= l) mod(ls, l, r, x);
	if(mid < r) mod(rs, l, r, x);
	pushup(p);
}

void modify(int p, int pos, int x) {
	if(t[p].l == t[p].r) return t[p].mx = t[p].val = x, void();
	if(mid >= pos) modify(ls, pos, x);
	else modify(rs, pos, x);
	pushup(p);
}

ll query(int p, int l, int r) {
	if(l <= t[p].l && t[p].r <= r) return t[p].val;
	ll res = 0;
	if(mid >= l) res += query(ls, l, r);
	if(mid < r) res += query(rs, l, r);
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	build(1, 1, n);
	for(int i = 1, op, l, r, p, x; i <= m; ++i) {
		scanf("%d", &op);
		if(op == 1) scanf("%d%d", &l, &r), printf("%lld\n", query(1, l, r));
		if(op == 2) scanf("%d%d%d", &l, &r, &x), mod(1, l, r, x);
		if(op == 3) scanf("%d%d", &p, &x), modify(1, p, x);
	}
	return 0;
}