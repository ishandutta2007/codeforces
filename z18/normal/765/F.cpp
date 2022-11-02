#include <bits/stdc++.h>
#define ls (x << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 1e5, logn = 16, maxm = 3e5, maxk = maxn * 32 + maxm, inf = 2e9;
int n, a[maxn + 3], m, lft[maxm + 3], rht[maxm + 3], res[maxm + 3], ans[maxm + 3];
int k, tmp[maxn + 3], mn[maxm + 3], tot;

struct event {
	int op, l, r, t;
	bool operator < (const event &t) const {
		return l == t.l ? op < t.op : l > t.l;
	}
} ev[maxk + 3];

void new_event(int op, int l, int r, int t) {
	ev[++tot].op = op, ev[tot].l = l, ev[tot].r = r, ev[tot].t = t;
}

void build(int x, int l, int r, int v) {
	mn[x] = v;
	if (l == r) return;
	build(ls, l, mid, v);
	build(rs, mid + 1, r, v);
}

void maintain(int x) {
	mn[x] = min(mn[ls], mn[rs]);
}

void modify(int x, int l, int r, int y, int z) {
	if (l == r) { mn[x] = min(mn[x], z); return; }
	if (y <= mid) modify(ls, l, mid, y, z);
	else modify(rs, mid + 1, r, y, z);
	maintain(x);
}

int query(int x, int l, int r, int lx, int rx) {
	if (l >= lx && r <= rx) return mn[x];
	int ans = inf;
	if (lx <= mid) ans = min(ans, query(ls, l, mid, lx, rx));
	if (rx > mid) ans = min(ans, query(rs, mid + 1, r, lx, rx));
	return ans; 
}

void solve() {
	for (int i = 1; i <= n; i++) tmp[i] = a[i];
	sort(tmp + 1, tmp + n + 1);
	k = unique(tmp + 1, tmp + n + 1) - (tmp + 1);
	tot = 0;
	build(1, 1, k, n + 1);
	for (int i = n; i; i--) {
		int u = lower_bound(tmp + 1, tmp + k + 1, a[i]) - tmp;
		int x = query(1, 1, k, 1, u);
		while (true) {
			if (x == n + 1) break;
			new_event(1, i, x, a[i] - a[x]);
			if (a[i] == a[x]) break;
			int t = a[i] - (a[i] - a[x]) / 2;
			int l = lower_bound(tmp + 1, tmp + k + 1, t) - tmp;
			x = query(1, 1, k, l, u);
		}
		modify(1, 1, k, u, i);
	}
	for (int i = 1; i <= m; i++) new_event(2, lft[i], rht[i], i);
	sort(ev + 1, ev + tot + 1);
	build(1, 1, n, inf);
	for (int i = 1; i <= tot; i++) {
		if (ev[i].op == 1) modify(1, 1, n, ev[i].r, ev[i].t);
		else res[ev[i].t] = query(1, 1, n, 1, ev[i].r);
	}
	for (int i = 1; i <= m; i++) ans[i] = min(ans[i], res[i]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &lft[i], &rht[i]);
	}
	fill(ans + 1, ans + m + 1, inf);
	solve();
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		int l = lft[i], r = rht[i];
		lft[i] = n - r + 1, rht[i] = n - l + 1;
	}
	solve();
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}