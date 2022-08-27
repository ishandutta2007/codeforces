#include <bits/stdc++.h>
#define fprintf(...) ((void)0)

typedef std::pair <int, int> pr;
typedef std::set <int> set;
typedef std::multiset <int> mset;
typedef set::iterator sit;
const int N = 500054;

int n, val;
int a[N], b[N];
int final[N];
pr c[N];
set R;
mset len;

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void modify(int l, int r) {
	sit it = R.lower_bound(l), jt;
	if (it == R.end() || *it > r) return;
	for (jt = it; jt != R.end() && *jt <= r; ++jt) final[*jt] = val;
	R.erase(it, jt);
}

namespace pb_ds {
	set C;

	inline void init() {
		for (int i = 0; i <= n + 1; ++i) C.emplace(i), len.emplace(0);
	}

	inline void handle(int l, int r) {
		fprintf(stderr, "handle %d %d\n", l, r);
		len.emplace(r - l);
		if (b[l] && b[r]) return modify(l, r);
		else if (!b[l] && !b[r]) return;
		assert((l ^ r) & 1);
		if (b[l]) modify(l, (l + r - 1) / 2);
		if (b[r]) modify((l + r + 1) / 2, r);
	}

	inline void detach(int l, int r) {
		fprintf(stderr, "detach %d %d\n", l, r);
		auto it = len.find(r - l); assert(it != len.end());
		len.erase(it);
	}

	void toggle(int pos) {
		assert(!b[pos]), b[pos] = 1;
		fprintf(stderr, "toggle %d\n", pos);
		sit i1, i2, i3, i4;
		if (b[pos - 1] && b[pos + 1]) {
			i3 = C.emplace(pos + 1).first;
			i2 = C.emplace(pos).first;
			--(i1 = i2), ++(i4 = i3);
			detach(*i1, *i4 - 1);
			handle(*i1, pos - 1), handle(pos, pos), handle(pos + 1, *i4 - 1);
		} else if (b[pos - 1]) {
			C.erase(pos + 1);
			i2 = C.emplace(pos).first;
			--(i1 = i2), ++(i3 = i2);
			detach(*i1, pos), detach(pos + 1, *i3 - 1);
			handle(*i1, pos - 1), handle(pos, *i3 - 1);
		} else if (b[pos + 1]) {
			C.erase(pos);
			i2 = C.emplace(pos + 1).first;
			--(i1 = i2), ++(i3 = i2);
			detach(*i1, pos - 1), detach(pos, *i3 - 1);
			handle(*i1, pos), handle(pos + 1, *i3 - 1);
		} else {
			i2 = C.find(pos), assert(i2 != C.end());
			C.erase(i2--), C.erase(pos + 1), ++(i3 = i2);
			detach(*i2, pos - 1), detach(pos, pos), detach(pos + 1, *i3 - 1);
			handle(*i2, *i3 - 1);
		}
		b[pos] = 1;
	}

	void toggle_head() {
		fprintf(stderr, "togglehead\n");
		assert(!b[1]), *b = b[1] = 1;
		sit i1, i2;
		if (b[2]) {
			i1 = C.emplace(2).first, ++(i2 = i1);
			detach(1, *i2 - 1), handle(1, 1), handle(2, *i2 - 1);
		} else {
			i2 = C.find(2), assert(i2 != C.end()), C.erase(i2++),
			handle(1, *i2 - 1), detach(1, 1), detach(2, *i2 - 1);
		}
	}

	void toggle_tail() {
		fprintf(stderr, "toggletail\n");
		assert(!b[n]), b[n + 1] = b[n] = 1;
		sit i1, i2;
		if (b[n - 1]) {
			i1 = C.emplace(n).first, --(i2 = i1);
			detach(*i2, n), handle(*i2, n - 1), handle(n, n);
		} else {
			i2 = C.find(n), assert(i2 != C.end()), C.erase(i2--);
			handle(*i2, n), detach(*i2, n - 1), detach(n, n);
		}
	}
}

int main() {
	int i, pos, ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), c[i - 1] = pr(a[i], i);
	if (n == 1) return printf("0\n%d\n", a[1]), 0;
	std::sort(c, c + n), final[1] = a[1], final[n] = a[n];
	for (i = 1; i <= n; ++i) R.emplace(i);
	pb_ds::init();
	for (i = 0; i < n; ++i) {
		std::tie(val, pos) = c[i];
		if (pos == 1) pb_ds::toggle_head();
		else if (pos == n) pb_ds::toggle_tail();
		else pb_ds::toggle(pos);
		if (i == n - 1 || c[i + 1].first != val) up(ans, *len.rbegin());
	}
	printf("%d\n", ans / 2);
	for (i = 1; i <= n; ++i) printf("%d%c", final[i], i == n ? 10 : 32);
	return 0;
}