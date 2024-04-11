#include <bits/stdc++.h>
#define ls (x << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 3e5, maxm = 1 << 20;
int n, a[maxn + 3], mn[maxm + 3], tag[maxm + 3];

void update(int x, int y) {
	mn[x] += y, tag[x] += y;
}

void push_down(int x) {
	update(ls, tag[x]), update(rs, tag[x]), tag[x] = 0;
}

void maintain(int x) {
	mn[x] = min(mn[ls], mn[rs]);
}

void modify(int x, int l, int r, int lx, int rx, int y) {
	if (l >= lx && r <= rx) return update(x, y);
	push_down(x);
	if (lx <= mid) modify(ls, l, mid, lx, rx, y);
	if (rx > mid) modify(rs, mid + 1, r, lx, rx, y);
	maintain(x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[x] = i;
	int ans = n;
	modify(1, 1, n, 1, a[n], -1);
	for (int i = 1, x; ; i++) {
		printf("%d%c", ans, " \n"[i == n]);
		if (i == n) break;
		scanf("%d", &x);
		modify(1, 1, n, 1, x, 1);
		while (mn[1] >= 0) modify(1, 1, n, 1, a[--ans], -1);
	}
	return 0;
}