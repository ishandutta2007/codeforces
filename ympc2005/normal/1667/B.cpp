#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, a[N], m, f[N], T;

ll ans = 1e18, b[N], c[N];

namespace Seg {
	int mx[N<<2][3];

	void build_(int o, int l, int r) {
		mx[o][0] = mx[o][1] = mx[o][2] = -1e9;

		if (l == r) {
			return;
		}

		int mid = (l + r)>>1;
		build_(o<<1, l, mid);
		build_(o<<1|1, mid + 1, r);
	}

	void upd_(int o, int l, int r, int x, int y) {
		mx[o][0] = max(mx[o][0], f[y]);
		mx[o][1] = max(mx[o][1], f[y] + y);
		mx[o][2] = max(mx[o][2], f[y] - y);
		
		if (l == r) {
			return;
		}

		int mid = (l + r)>>1;
		
		if (x <= mid) {
			upd_(o<<1, l, mid, x, y);
		} else {
			upd_(o<<1|1, mid + 1, r, x, y);
		}
	}

	int ask_(int o, int l, int r, int x, int y, int k) {
		if (x <= l && r <= y) {
			return mx[o][k];
		}

		int res = -1e9, mid = (l + r)>>1;

		if (x <= mid) {
			res = max(res, ask_(o<<1, l, mid, x, y, k));
		}

		if (mid < y) {
			res = max(res, ask_(o<<1|1, mid + 1, r, x, y, k));
		}

		return res;
	}
}

int id_(ll x) {
	return lower_bound(c, c + m + 1, x) - c;
}

void work_() {
	scanf("%d", &n);
	c[0] = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
		c[i] = b[i];
	}

	sort(c, c + n + 1);
	m = unique(c, c + n + 1) - c - 1;
	Seg :: build_(1, 0, m);
	Seg :: upd_(1, 0, m, id_(b[0]), 0);

	for (int i = 1; i <= n; i++) {
		int x = id_(b[i]);
		f[i] = Seg :: ask_(1, 0, m, x, x, 0);

		if (x < m) {
			f[i] = max(f[i], Seg :: ask_(1, 0, m, x + 1, m, 1) - i);
		}

		if (x > 0) {
			f[i] = max(f[i], Seg :: ask_(1, 0, m, 0, x - 1, 2) + i);
		}

		Seg :: upd_(1, 0, m, x, i);
	}

	printf("%d\n", f[n]);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		work_();
	}
}