#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long a[105], b[100005];
struct ST {
	int len[400005];
	long long sum[400005], lazy[400005];
	void build(int p, int l, int r) {
		len[p] = r - l + 1;
		if (l == r) {
			sum[p] = b[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		sum[p] = sum[p << 1] + sum[p << 1 | 1];
	}
	inline void tag(int p, long long x) {
		sum[p] += len[p] * x;
		lazy[p] += x;
	}
	inline void pushdown(int p) {
		if (lazy[p]) {
			tag(p << 1, lazy[p]);
			tag(p << 1 | 1, lazy[p]);
			lazy[p] = 0;
		}
	}
	void modify(int p, int l, int r, int ll, int rr, long long x) {
		if (l >= ll && r <= rr) {
			tag(p, x);
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(p);
		if (mid >= ll) {
			modify(p << 1, l, mid, ll, rr, x);
		}
		if (mid < rr) {
			modify(p << 1 | 1, mid + 1, r, ll, rr, x);
		}
		sum[p] = sum[p << 1] + sum[p << 1 | 1];
	}
	long long query(int p, int l, int r, int ll, int rr) {
		if (l >= ll && r <= rr) {
			return sum[p];
		}
		int mid = (l + r) >> 1;
		pushdown(p);
		long long res = 0;
		if (mid >= ll) {
			res += query(p << 1, l, mid, ll, rr);
		}
		if (mid < rr) {
			res += query(p << 1 | 1, mid + 1, r, ll, rr);
		}
		return res;
	}
} tr;
struct ST2 {
	long long sum[400005];
	void build(int p, int l, int r) {
		if (l == r) {
			sum[p] = b[l] - b[l - 1];
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		sum[p] = sum[p << 1] + sum[p << 1 | 1];
	}
	void modify(int p, int l, int r, int pos, int val) {
		sum[p] += val;
		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		if (mid >= pos) {
			modify(p << 1, l, mid, pos, val);
		} else {
			modify(p << 1 | 1, mid + 1, r, pos, val);
		}
	}
	int query(int p, int l, int r, long long rest) {
		if (l == r) return rest < sum[p] ? (l - 1) : l;
		int mid = (l + r) >> 1;
		if (sum[p << 1] >= rest) {
			return query(p << 1, l, mid, rest);
		} else {
			return query(p << 1 | 1, mid + 1, r, rest - sum[p << 1]);
		}
	}
} tr2;
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &b[i]);
	}
	long long s = a[1] + b[1];
	for (int i = 1; i < n; ++i) {
		a[i] = a[i + 1] - a[i];
	}
	long long offset = 0;
	for (int i = 1; i < m; ++i) {
		b[i] = b[i + 1] - b[i];
		offset += b[i] * (m - i);
	}
	tr.build(1, 1, m - 1); 
	tr2.build(1, 1, m - 1); 
	while (q--) {
		int type, k, d;
		scanf("%d%d%d", &type, &k, &d);
		if (type == 1) {
			if (k == n) {
				s += d;
				--k;
			}
			for (int i = n - k; i < n; ++i) {
				a[i] += d;
			}
		} else {
			if (k == m) {
				s += d;
				--k;
			}
			offset += 1ll * k * (k + 1) / 2 * d;
			tr.modify(1, 1, m - 1, m - k, m - 1, d);
			tr2.modify(1, 1, m - 1, m - k, d);
		}
		long long ans = offset;
		ans += s * (n + m - 1);
		for (int i = 1; i < n; ++i) {
			int pos = tr2.query(1, 1, m - 1, a[i]);
			if (pos > 0) {
				ans += tr.query(1, 1, m - 1, 1, pos);
			}
			ans += (n + m - 1 - (pos + i)) * a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}