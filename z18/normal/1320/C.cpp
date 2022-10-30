#include <bits/stdc++.h>
#define ls (x << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 2e5, maxk = 1e6, maxm = 1 << 21, inf = 2e9;
int n, m, p, tot, a[maxn + 3], b[maxn + 3], ca[maxn + 3], cb[maxn + 3], x[maxn + 3], y[maxn + 3], z[maxn + 3];
int mx[maxk + 3], seg[maxm + 3], tag[maxm + 3];

struct event {
	int t, x, i;
	friend bool operator < (const event &a, const event &b) {
		return a.x == b.x ? a.t < b.t : a.x < b.x;
	}
} ev[maxk + 3];

void add(int t, int x, int i) {
	ev[++tot].t = t, ev[tot].x = x, ev[tot].i = i;
}

void maintain(int x) {
	seg[x] = max(seg[ls], seg[rs]);
}

void build(int x, int l, int r) {
	if (l == r) { seg[x] = mx[l]; return; }
	build(ls, l, mid), build(rs, mid + 1, r);
	maintain(x);
}

void push_down(int x) {
	tag[ls] += tag[x], seg[ls] += tag[x];
	tag[rs] += tag[x], seg[rs] += tag[x];
	tag[x] = 0;
}

void modify(int x, int l, int r, int lx, int rx, int y) {
	if (l >= lx && r <= rx) { seg[x] += y, tag[x] += y; return; }
	push_down(x);
	if (lx <= mid) modify(ls, l, mid, lx, rx, y);
	if (rx > mid) modify(rs, mid + 1, r, lx, rx, y);
	maintain(x);
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &ca[i]), add(1, a[i], i);
	for (int i = 1; i <= maxk; i++) mx[i] = -inf;
	for (int i = 1; i <= m; i++) scanf("%d %d", &b[i], &cb[i]), mx[b[i]] = max(mx[b[i]], -cb[i]);
	build(1, 1, maxk);
	for (int i = 1; i <= p; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]), add(2, x[i], i);
	sort(ev + 1, ev + tot + 1);
	int ans = -inf;
	for (int i = 1; i <= tot; i++) {
		if (ev[i].t == 1) ans = max(ans, seg[1] - ca[ev[i].i]);
		else if (y[ev[i].i] < maxk) modify(1, 1, maxk, y[ev[i].i] + 1, maxk, z[ev[i].i]);
	}
	printf("%d\n", ans);
	return 0;
}