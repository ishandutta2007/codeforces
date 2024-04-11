#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n, q;
int a[N];

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {
		ll sum, pre, suf, ans, npre, nsuf;
	} x[265000];

	inline void update(node &ret, const node &l, const node &r) {
		ret.sum = l.sum + r.sum,
		ret.pre = std::max(l.pre, l.sum + r.pre),
		ret.suf = std::max(r.suf, l.suf + r.sum),
		ret.npre = std::min(l.npre, l.sum + r.npre),
		ret.nsuf = std::min(r.nsuf, l.nsuf + r.sum),
		ret.ans = std::max({l.ans, r.ans, l.suf + r.pre, -l.nsuf - r.npre});
	}

	void build(int id, int L, int R) {
		if (L == R) {
			x[id].sum = a[L], x[id].pre = x[id].suf = std::max(a[L], 0), x[id].npre = x[id].nsuf = std::min(a[L], 0), x[id].ans = abs(a[L]);
			return;
		}
		segc; build(lc, L, M), build(rc, M + 1, R);
		update(x[id], x[lc], x[rc]);
	}

	node range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id];
		segc;
		if (qr <= M) return range(lc, L, M, ql, qr);
		if (ql > M) return range(rc, M + 1, R, ql, qr);
		node ret, l(range(lc, L, M, ql, M)), r(range(rc, M + 1, R, M + 1, qr));
		return update(ret, l, r), ret;
	}
}

int main() {
	int i, x, l, r; ST::node ret;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) cin >> x, a[i] = x - a[i];
	ST::build(1, 1, n);
	for (; q; --q)
		cin >> l >> r, ret = ST::range(1, 1, n, l, r),
		cout << (ret.npre < 0 || ret.suf > 0 ? -1 : ret.ans) << '\n';
	return 0;
}