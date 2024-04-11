#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::array <int, 4> array;
const int N = 100054, INF = 0x3f3f3f3f;

struct ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1

	int W;
	struct node {
		array v, rv; int c, d, rev;
		inline static node single(int a, int b) {
			node ret;
			ret.v = {a + b, INF, INF, !a + !b},
			ret.rv = {a + !b, INF, INF, !a + b},
			ret.c = a, ret.d = b, ret.rev = 0;
			return ret;
		}
	} x[262200];

	inline void update(node &ret, const node &l, const node &r) {
	#define U(x, y, z) std::min({l.x[y] + r.x[z], l.x[y] + r.x[2 + z] + W, l.x[1 + y] + r.x[z] + W, l.x[1 + y] + r.x[2 + z]})
		ret.v = {U(v, 0, 0), U(v, 0, 1), U(v, 2, 0), U(v, 2, 1)},
		ret.rv = {U(rv, 0, 0), U(rv, 0, 1), U(rv, 2, 0), U(rv, 2, 1)},
		ret.c = l.c + r.c, ret.d = l.d + r.d;
	}

	void build(int id, int L, int R, char *s1, char *s2) {
		if (L == R) {x[id] = node::single(s1[L] >> 4 & 1, s2[L] >> 4 & 1); return;}
		segc; build(lc, L, M, s1, s2), build(rc, M + 1, R, s1, s2);
		update(x[id], x[lc], x[rc]);
	}
} H, V;

int R, C, q;
char le[N], ri[N], tp[N], bo[N];

int accumulate() {
	const ST::node &h = H.x[1], &v = V.x[1];
	return std::min({
		h.v[0] + v.c + v.d,
		h.v[1] + v.c + (C - v.d),
		h.v[2] + (C - v.c) + v.d,
		h.v[3] + (C - v.c) + (C - v.d),
		v.v[0] + h.c + h.d,
		v.v[1] + h.c + (R - h.d),
		v.v[2] + (R - h.c) + h.d,
		v.v[3] + (R - h.c) + (R - h.d)
	});
}

int main() {
	int l, r; char op[3];
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> R >> C >> q >> le >> ri >> tp >> bo;
	H.W = C, H.build(1, 1, R, le - 1, ri - 1),
	V.W = R, V.build(1, 1, C, tp - 1, bo - 1);
	cout << accumulate() << '\n';
	return 0;
}