#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5, maxm = 1 << 18, mod = 998244353;
int n, x[maxn + 3], v[maxn + 3], p[maxn + 3];
int tot, res[maxm + 3][2][2], ans[maxm + 3];

struct event {
	int id, p, q, x, y;
	friend bool operator < (const event &a, const event &b) {
		return 1ll * a.p * b.q < 1ll * b.p * a.q;
	}
} ev[maxm + 3];

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

#define ls (x << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)

void maintain(int x, int l, int r) {
	int t = p[mid + 1];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res[x][i][j] = 1ll * (1 - t + mod) * res[ls][i][0] % mod * res[rs][0][j] % mod;
			res[x][i][j] = (res[x][i][j] + 1ll * t * res[ls][i][1] % mod * res[rs][1][j]) % mod;
		}
	}
}

void build(int x, int l, int r) {
	if (l == r) {
		res[x][0][0] = res[x][0][1] = 1;
		res[x][1][0] = res[x][1][1] = 1;
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	maintain(x, l, r);
}

void modify(int x, int l, int r, int y, int a, int b) {
	if (l == r) {
		res[x][a][b] = 0;
		return;
	}
	if (y <= mid) {
		modify(ls, l, mid, y, a, b);
	} else {
		modify(rs, mid + 1, r, y, a, b);
	}
	maintain(x, l, r);
}

int main() {
	scanf("%d", &n);
	int t = qpow(100, mod - 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &x[i], &v[i], &p[i]);
		p[i] = 1ll * p[i] * t % mod;
	}
	for (int i = 1; i < n; i++) {
		ev[++tot].id = i;
		ev[tot].p = x[i + 1] - x[i];
		ev[tot].q = v[i] + v[i + 1];
		ev[tot].x = 1, ev[tot].y = 0;
		if (v[i] > v[i + 1]) {
			ev[++tot].id = i;
			ev[tot].p = x[i + 1] - x[i];
			ev[tot].q = v[i] - v[i + 1];
			ev[tot].x = 1, ev[tot].y = 1;
		}
		if (v[i] < v[i + 1]) {
			ev[++tot].id = i;
			ev[tot].p = x[i + 1] - x[i];
			ev[tot].q = -v[i] + v[i + 1];
			ev[tot].x = 0, ev[tot].y = 0;
		}
	}
	sort(ev + 1, ev + tot + 1);
	build(1, 0, n);
	ans[0] = res[1][0][0];
	for (int i = 1; i <= tot; i++) {
		modify(1, 0, n, ev[i].id, ev[i].x, ev[i].y);
		ans[i] = res[1][0][0];
	}
	int x = 0;
	for (int i = 1; i <= tot; i++) {
		x = (x + 1ll * (ans[i - 1] - ans[i] + mod) * ev[i].p % mod * qpow(ev[i].q, mod - 2)) % mod;
	}
	printf("%d\n", x);
	return 0;
}