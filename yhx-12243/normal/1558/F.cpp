#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 200054, INF = 0x3f3f3f3f;

int n;
int a[N], b[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void up(pr &x, const pr &y) {up(x.first, y.first), up(x.second, y.second);}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline pr max(const pr &x, const pr &y) {return pr(max(x.first, y.first), max(x.second, y.second));}
inline pr operator + (const pr &x, const int y) {return pr(x.first + y, x.second + y);}

namespace pb_ds {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int c;

	struct node {
		pr v; int tag, max;
		inline void init(int x) {max = 0, v = pr(-x, x) + -(x & 1);}
	} x[530000];

	inline void update(node &ret, const node &l, const node &r) {
		ret.v = max(l.v, r.v) + 2 * ret.tag, ret.max = max(l.max, r.max) + ret.tag;
	}

	void build(int id, int L, int R) {
		x[id].tag = 0;
		if (L == R) return x[id].init(L);
		segc; build(lc, L, M), build(rc, M + 1, R),
		update(x[id], x[lc], x[rc]);
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v = x[id].v + 2 * v, x[id].tag += v, x[id].max += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	pr range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id].v;
		segc; pr s(-INF, -INF);
		if (ql <= M) up(s, range(lc, L, M, ql, qr));
		if (qr > M) up(s, range(rc, M + 1, R, ql, qr));
		return s + 2 * x[id].tag;
	}

	int locate_left(int id, int L, int R) {
		int base = 0;
		if (!x[id].max) return R + 1;
		for (; L != R; ) {
			segc; base -= x[id].tag;
			if (x[lc].max == base) L = M + 1, id = rc;
			else R = M, id = lc;
		}
		return L;
	}

	int locate_right(int id, int L, int R) {
		int base = 0;
		if (!x[id].max) return L - 1;
		for (; L != R; ) {
			segc; base -= x[id].tag;
			if (x[rc].max == base) R = M, id = lc;
			else L = M + 1, id = rc;
		}
		return L;
	}

	inline void init() {c = 0, build(1, 1, n - 1);}

	inline int get() {
		int center = n - c, ret = 0, left = locate_left(1, 1, n - 1), right = locate_right(1, 1, n - 1);
		if (left <= center) up(ret, center + range(1, 1, n - 1, left, center).first);
		if (center <= right) up(ret, -center + range(1, 1, n - 1, center, right).second);
		return ret;
	}

	inline void suffix(int h, int v) {if (h < n) add(1, 1, n - 1, h, n - 1, v);}
	inline void set(int x) {suffix(n - c++, -1), suffix(x, 1);}
}

void work() {
	int i, ans = 0;
	cin >> n, pb_ds::init();
	for (i = 1; i <= n; ++i) cin >> a[i], b[a[i]] = i;
	for (i = n; i > 1; --i) pb_ds::set(b[i]), up(ans, pb_ds::get());
	cout << ans << '\n';
}

int main() {
	int T;
	//std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}