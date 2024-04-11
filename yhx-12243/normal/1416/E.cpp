#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <ll, int> pr;
const int N = 500054, INF = 0x3f3f3f3f; 

int n, W;
int a[N], f[N];
ll Le[N], Ri[N], Mid[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

namespace DC {
	const int N = ::N * 4;

	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	#define exist_pd if (x[id].tag != INF || x[id].set != INF) push_down(x[id], x[lc], x[rc])
	struct node {int v, tag, set;} x[2100000];

	void build(int id, int L, int R) {
		x[id].v = INF - 1, x[id].tag = x[id].set = INF;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	inline void node_min(node &ret, int v) {down(ret.v, v), ret.set == INF ? down(ret.tag, v) : down(ret.set, v);}

	inline void cover(node &ret, int v) {ret.set = ret.v = v, ret.tag = INF;}

	inline void push_down(node &ret, node &l, node &r) {
		if (ret.set == INF) node_min(l, ret.tag), node_min(r, ret.tag), ret.tag = INF;
		else cover(l, ret.set), cover(r, ret.set), ret.set = INF; 
	}

	void min(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return node_min(x[id], v);
		segc; exist_pd;
		if (ql <= M) min(lc, L, M, ql, qr, v);
		if (qr > M) min(rc, M + 1, R, ql, qr, v);
		x[id].v = ::min(x[lc].v, x[rc].v);
	}

	void clear(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return cover(x[id], INF - 1);
		segc; exist_pd;
		if (ql <= M) clear(lc, L, M, ql, qr);
		if (qr > M) clear(rc, M + 1, R, ql, qr);
		x[id].v = ::min(x[lc].v, x[rc].v);
	}

	void decr(int id, int L, int R, int h) {
		if (L == R) {--x[id].v; return;}
		segc; exist_pd;
		h <= M ? decr(lc, L, M, h) : decr(rc, M + 1, R, h);
		x[id].v = ::min(x[lc].v, x[rc].v);
	}
}

void work() {
	int i, li, ri; ll l = 0, r;
	cin >> n;
	for (i = 0; i < n; ++i, l = r) {
		cin >> a[i], r = (a[i] -= 2) - l,
		i & 1 ? (Le[i] = -l, Ri[i] = r) : (Le[i] = -r, Ri[i] = l),		
		DC::D[i].first = Le[i], DC::D[i + n].first = Ri[i] + 1;
		if (a[i] & 1)
			Mid[i] = 0,
			DC::D[i + 2 * n].first = Le[i],
			DC::D[i + 3 * n].first = Ri[i] + 1;
		else
			Mid[i] = (Le[i] + Ri[i]) / 2,
			DC::D[i + 2 * n].first = Mid[i],
			DC::D[i + 3 * n].first = Mid[i] + 1;
	}
	for (i = 0; i < 4 * n; ++i) DC::D[i].second = i;
	W = DC::Discretize(4 * n);
	ST::build(1, 0, W - 1); 
	for (*f = i = 0; i < n; ++i) {
		li = DC::F[i], ri = DC::F[i + n];
		if (li) ST::clear(1, 0, W - 1, 0, li - 1);
		if (ri < W) ST::clear(1, 0, W - 1, ri, W - 1);
		ST::min(1, 0, W - 1, li, ri - 1, f[i] - i);
		if (!(a[i] & 1)) ST::decr(1, 0, W - 1, DC::F[i + 2 * n]);
		f[i + 1] = i + 2 + ST::x[1].v;
	}
	cout << f[n] << '\n';
}

int main() {
	int T; 
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}