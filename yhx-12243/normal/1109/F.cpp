#include <bits/stdc++.h>
#define G(i, j) (((i) - 1) * C + (j))
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 200054, U = 1054;

int n, R, C;
int a[U][U], right[N];
bool used[N];
pr pos[N];

namespace LCT {
	#define pa p[nd]
	struct node {bool rev; int p, c[2];} nd[N];
	inline int dir(int x) {return !nd[x].p ? -1 : x == nd[x].pa.c[0] ? 0 : x == nd[x].pa.c[1] ? 1 : -1;}
	inline void set(int x, int px, int c) {if (nd[x].p = px, ~c) nd[px].c[c] = x;}
	inline void reverse(int x) {x && (std::swap(nd[x].c[0], nd[x].c[1]), nd[x].rev = !nd[x].rev);}
	void push_down(int x) {if (nd[x].rev) reverse(nd[x].c[0]), reverse(nd[x].c[1]), nd[x].rev = false;}
	void pull_down(int x) {if (~dir(x)) pull_down(nd[x].p); push_down(x);}
	void rotate(int x) {int y = nd[x].p, d = !dir(x); set(nd[x].c[d], y, !d), set(x, nd[y].p, dir(y)), set(y, x, d);}
	void splay(int x) {for (pull_down(x); ~dir(x); rotate(x)) if (~dir(nd[x].p)) rotate(dir(x) ^ dir(nd[x].p) ? x : nd[x].p);}
	void access(int x) {for (int y = 0; x; y = x, x = nd[x].p) splay(x), nd[x].c[1] = y;}
	void make_root(int x) {access(x), splay(x), reverse(x);}
	int find_root(int x) {for (access(x), splay(x); push_down(x), nd[x].c[0]; x = nd[x].c[0]); return splay(x), x;}
	int split(int x, int y) {return make_root(x), access(y), splay(y), y;}
	void link(int x, int y) {make_root(x), nd[x].p = y;}
	void cut(int x, int y) {split(x, y), nd[x].p = nd[y].c[0] = 0;}
}

inline bool insert(int x) {
	int r, c, $1, $2, $3, $4, _1, _2, _3, _4;
	std::tie(r, c) = pos[x];
	_1 = used[$1 = a[r][c - 1]] ? LCT::find_root($1) : -1;
	_2 = used[$2 = a[r - 1][c]] ? LCT::find_root($2) : -2;
	_3 = used[$3 = a[r][c + 1]] ? LCT::find_root($3) : -3;
	_4 = used[$4 = a[r + 1][c]] ? LCT::find_root($4) : -4;
	if (_1 == _2 || _1 == _3 || _2 == _3 || _1 == _4 || _2 == _4 || _3 == _4) return false;
	if (used[$1]) LCT::link($1, x);
	if (used[$2]) LCT::link($2, x);
	if (used[$3]) LCT::link($3, x);
	if (used[$4]) LCT::link($4, x);
	return used[x] = true;
}

inline void erase(int x) {
	int r, c; assert(used[x]);
	std::tie(r, c) = pos[x];
	if (used[a[r][c - 1]]) LCT::cut(x, a[r][c - 1]);
	if (used[a[r - 1][c]]) LCT::cut(x, a[r - 1][c]);
	if (used[a[r][c + 1]]) LCT::cut(x, a[r][c + 1]);
	if (used[a[r + 1][c]]) LCT::cut(x, a[r + 1][c]);
	used[x] = false;
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int v, c, tag;} x[530000];

	void build(int id, int L, int R) {
		x[id].tag = x[id].v = 0, x[id].c = R - L + 1; if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	inline void update(node &ret, const node &l, const node &r) {
		if (l.v == r.v) ret.v = l.v, ret.c = l.c + r.c;
		else if (l.v < r.v) ret.v = l.v, ret.c = l.c;
		else ret.v = r.v, ret.c = r.c;
		ret.v += ret.tag;
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	node range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id];
		segc; node ret, l, r;
		if (qr <= M) return ret = range(lc, L, M, ql, qr), ret.v += x[id].tag, ret;
		if (ql > M) return ret = range(rc, M + 1, R, ql, qr), ret.v += x[id].tag, ret;
		l = range(lc, L, M, ql, M), r = range(rc, M + 1, R, M + 1, qr);
		return ret.tag = x[id].tag, update(ret, l, r), ret;
	}
}

int main() {
	int i, j, r, c, t, bp[6]; long long ans = 0; ST::node z;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> R >> C, n = R * C;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j) cin >> a[i][j], pos[ a[i][j] ] = pr(i, j);
	for (j = i = 1; i <= n; erase(i), right[i++] = j - 1)
		for (; j <= n && insert(j); ++j);
	ST::build(1, 1, n);
	for (i = n; i; --i) {
		std::tie(r, c) = pos[i], *bp = i, t = 1;
		if (a[r][c - 1] > i) bp[t++] = a[r][c - 1];
		if (a[r - 1][c] > i) bp[t++] = a[r - 1][c];
		if (a[r][c + 1] > i) bp[t++] = a[r][c + 1];
		if (a[r + 1][c] > i) bp[t++] = a[r + 1][c];
		std::sort(bp, bp + t), bp[t] = n + 1;
		for (j = 0; j < t; ++j) if (j != 1) ST::add(1, 1, n, bp[j], bp[j + 1] - 1, 1 - j);
		z = ST::range(1, 1, n, i, right[i]);
		if (z.v == 1) ans += z.c;
	}
	cout << ans << '\n';
	return 0;
}