#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs (ls | 1)
using namespace std;

typedef long long ll;
const int maxn = 1e5, maxm = 1 << 18;
int n, m, k, bit, a[maxn + 3], b[maxn + 3], c[maxn + 3], d[maxn + 3];
int cnt, pos[maxn + 3], tot, cov[maxm + 3], len[maxm + 3], ans[50];

struct event {
	int x, l, r, y;
	friend bool operator < (const event &a, const event &b) {
		return a.x == b.x ? a.y > b.y : a.x < b.x;
	}
} eve[maxn + 3];

void maintain(int x, int l, int r) {
	if (cov[x]) {
		len[x] = pos[r + 1] - pos[l];
	} else if (l == r) {
		len[x] = 0;
	} else {
		len[x] = len[ls] + len[rs];
	}
}

void build(int x, int l, int r) {
	cov[x] = len[x] = 0;
	if (l == r) {
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

void modify(int x, int l, int r, int lx, int rx, int y) {
	if (l >= lx && r <= rx) {
		cov[x] += y;
		maintain(x, l, r);
		return;
	}
	if (lx <= mid) {
		modify(ls, l, mid, lx, rx, y);
	}
	if (rx > mid) {
		modify(rs, mid + 1, r, lx, rx, y);
	}
	maintain(x, l, r);
}

ll solve() {
	cnt = tot = 0;
	for (int i = 1; i <= m; i++) if (b[i] < d[i]) {
		pos[++cnt] = b[i], pos[++cnt] = d[i];
	}
	if (!cnt) {
		return 0;
	}
	sort(pos + 1, pos + cnt + 1);
	cnt = unique(pos + 1, pos + cnt + 1) - (pos + 1);
	for (int i = 1; i <= m; i++) if (b[i] < d[i]) {
		int l = lower_bound(pos + 1, pos + cnt + 1, b[i]) - pos;
		int r = lower_bound(pos + 1, pos + cnt + 1, d[i]) - (pos + 1);
		eve[++tot].x = a[i], eve[tot].l = l, eve[tot].r = r, eve[tot].y = 1;
		eve[++tot].x = c[i], eve[tot].l = l, eve[tot].r = r, eve[tot].y = -1;
	}
	sort(eve + 1, eve + tot + 1);
	/*
	puts("-----");
	printf("%d\nP: ", cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d%c", pos[i], " \n"[i == cnt]);
	}
	for (int i = 1; i <= tot; i++) {
		printf("E: %d %d %d %d\n", eve[i].x, eve[i].l, eve[i].r, eve[i].y);
	}
	*/
	cnt--;
	build(1, 1, cnt);
	ll sum = 0;
	for (int i = 1; i <= tot; i++) {
		sum += 1ll * (eve[i].x - eve[i - 1].x) * len[1];
		modify(1, 1, cnt, eve[i].l, eve[i].r, eve[i].y);
	}
	return sum;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		a[i]--, b[i]--;
	}
	for (bit = 0; 1 << bit <= k; bit++);
	for (int i = 0; i < bit; i++) {
		ans[i] = solve() & 1;
		// puts("----------");
		// printf("! %d %lld\n", i, ans[i]);
		for (int j = 1; j <= m; j++) {
			a[j] >>= 1, b[j] >>= 1, c[j] >>= 1, d[j] >>= 1;
		}
		/*
		for (int j = 1; j <= m; j++) {
			printf("%d %d %d %d\n", a[j], b[j], c[j], d[j]);
		}
		*/
	}
	int sg = 0;
	for (int i = 0; i < bit; i++) {
		if (ans[i] ^ ans[i + 1]) {
			sg ^= 1 << i;
		}
	}
	if (sg) {
		puts("Hamed");
	} else {
		puts("Malek");
	}
	return 0;
}