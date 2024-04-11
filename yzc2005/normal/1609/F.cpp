#include <bits/stdc++.h>
using namespace std;
int n, b[1000005];
long long a[1000005];
int s1[1000005], t1;
int s2[1000005], t2;
struct event {
	int l, r, t, from;
	bool type;
};
vector<event> e[64];
struct ST {
	int sum[4000005], len[4000005], lazy[4000005];
	void build(int p, int l, int r) {
		len[p] = r - l + 1;
		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
	}
	inline void tag(int p, int x) {
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
	void modify(int p, int l, int r, int ll, int rr, int x) {
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
	int query(int p, int l, int r, int ll, int rr) {
		if (l >= ll && r <= rr) {
			return sum[p];
		}
		int mid = (l + r) >> 1;
		pushdown(p);
		int res = 0;
		if (mid >= ll) {
			res += query(p << 1, l, mid, ll, rr);
		}
		if (mid < rr) {
			res += query(p << 1 | 1, mid + 1, r, ll, rr);
		}
		return res;
	}
} tr1, tr2;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		b[i] = __builtin_popcountll(a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		while (t1 && a[i] > a[s1[t1]]) {
			e[b[s1[t1]]].push_back({s1[t1 - 1] + 1, s1[t1], i, 1, false});
			--t1;
		}
		e[b[i]].push_back({s1[t1] + 1, i, i, 1, true});
		s1[++t1] = i;
		while (t2 && a[i] < a[s2[t2]]) {
			e[b[s2[t2]]].push_back({s2[t2 - 1] + 1, s2[t2], i, 2, false});
			--t2;
		}
		e[b[i]].push_back({s2[t2] + 1, i, i, 2, true});
		s2[++t2] = i;
	}
	while (t1) {
		e[b[s1[t1]]].push_back({s1[t1 - 1] + 1, s1[t1], n + 1, 1, false});
		--t1;
	}
	while (t2) {
		e[b[s2[t2]]].push_back({s2[t2 - 1] + 1, s2[t2], n + 1, 2, false});
		--t2;
	}
	tr1.build(1, 1, n);
	tr2.build(1, 1, n);
	long long ans = 0;
	for (int k = 0; k < 64; ++k) {
		int last = 0, cur = 0;
		for (auto it : e[k]) {
			int l = it.l, r = it.r;
			ans += 1ll * cur * (it.t - last);
			last = it.t;
			if (it.from == 1) {
				if (it.type) {
					cur += tr2.query(1, 1, n, l, r);
					tr1.modify(1, 1, n, l, r, 1);
				} else {
					cur -= tr2.query(1, 1, n, l, r);
					tr1.modify(1, 1, n, l, r, -1);
				}
			} else {
				if (it.type) {
					cur += tr1.query(1, 1, n, l, r);
					tr2.modify(1, 1, n, l, r, 1);
				} else {
					cur -= tr1.query(1, 1, n, l, r);
					tr2.modify(1, 1, n, l, r, -1);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}