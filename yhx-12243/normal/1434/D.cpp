#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 500054, M = N * 2, INF = 0x3f3f3f3;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, q, E = 0;
int first[N], next[M];
int p[N], col[N], mapped[N];
int cnt = 0, o[M], id[N], eid[N];

inline int max(const int x, const int y) {return x < y ? y : x;}
inline int max(const int x, const int y, const int z) {return max(max(x, y), z);}
inline int max(const int x, const int y, const int z, const int w) {return max(max(x, y), max(z, w));}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].flip) push_down(x[id], x[lc], x[rc])

	struct node {
		int l, r, lc0, lc1, rc0, rc1, ld0, ld1, rd0, rd1, ans0, ans1; bool flip;
		node () {}
		node (int v) :
			l(0), r(0),
			lc0(-INF), lc1(-INF),
			rc0(-INF), rc1(-INF),
			ld0(-INF), ld1(-INF),
			rd0(-INF), rd1(-INF),
			ans0(-INF), ans1(-INF) {
			switch (v) {
				case -1: l = 1; break;
				case 0: r = lc0 = ld0 = 1, rc0 = rd0 = ans0 = 0; break;
				case 1: r = lc1 = ld1 = 1, rc1 = rd1 = ans1 = 0; break;
			}
		}
	} x[2100000];

	inline void update(node &ret, const node &x, const node &y) {
		ret = node(2),
		ret.l = max(x.l, x.l - x.r + y.l),
		ret.r = max(y.r, y.r - y.l + x.r),
		ret.lc0 = max(x.lc0, x.l - x.r + y.lc0, x.l + x.r + y.ld0),
		ret.lc1 = max(x.lc1, x.l - x.r + y.lc1, x.l + x.r + y.ld1),
		ret.rc0 = max(y.rc0, y.r - y.l + x.rc0, y.r + y.l + x.rd0),
		ret.rc1 = max(y.rc1, y.r - y.l + x.rc1, y.r + y.l + x.rd1),
		ret.ld0 = max(x.ld0, y.ld0 + x.r - x.l),
		ret.ld1 = max(x.ld1, y.ld1 + x.r - x.l),
		ret.rd0 = max(y.rd0, x.rd0 + y.l - y.r),
		ret.rd1 = max(y.rd1, x.rd1 + y.l - y.r),
		ret.ans0 = max(x.ans0, y.ans0, x.rc0 + y.ld0, x.rd0 + y.lc0),
		ret.ans1 = max(x.ans1, y.ans1, x.rc1 + y.ld1, x.rd1 + y.lc1);
	}

	inline void cover(node &ret) {
		std::swap(ret.lc0, ret.lc1), std::swap(ret.rc0, ret.rc1),
		std::swap(ret.ld0, ret.ld1), std::swap(ret.rd0, ret.rd1);
		std::swap(ret.ans0, ret.ans1), ret.flip = !ret.flip;
	}

	inline void push_down(node &ret, node &l, node &r) {cover(l), cover(r), ret.flip = false;}

	void build(int id, int L, int R) {	
		if (L == R) {x[id] = node(o[L]); return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		update(x[id], x[lc], x[rc]);
	}

	void adj(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return cover(x[id]);
		segc; exist_pd;
		if (ql <= M) adj(lc, L, M, ql, qr);
		if (qr > M) adj(rc, M + 1, R, ql, qr);
		update(x[id], x[lc], x[rc]);
	}
}

inline void addedge(int u, int v, int w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != p[x])
			p[y] = x, mapped[(i + 1) / 2] = y,
			col[y] = col[x] ^ e[i].w, dfs(y);
}

void dfs1(int x) {
	int i, y;
//	fprintf(stderr, "dfs1 %d\n", x);
	o[++cnt] = col[x], id[x] = cnt;
	for (i = first[x]; i; i = next[i]) if (p[y = e[i].v] == x) dfs1(y);
	o[++cnt] = -1, eid[x] = cnt;
}

int main() {
	int i, u, v, w;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v >> w, addedge(u, v, w);
	dfs(1), dfs1(1), assert(cnt == 2 * n);
	ST::build(1, 1, cnt);
//	for (i = 1; i <= 2 * n; ++i) fprintf(stderr, "o[%d] = %d\n", i, o[i]);
//	fprintf(stderr, "initial %d\n", max(ST::x[1].ans0, ST::x[1].ans1));
	for (cin >> q; q; --q)
		cin >> v, v = mapped[v],
		ST::adj(1, 1, cnt, id[v], eid[v]),
//		fprintf(stderr, "flipped [%d, %d]\n", id[v], eid[v]),
		cout << max(ST::x[1].ans0, ST::x[1].ans1) << '\n';
	return 0;
}