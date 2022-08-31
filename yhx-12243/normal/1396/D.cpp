#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::set <int> set;
const int N = 2054, mod = 1000000007;

int n, C, L, L2, Xn, Yn;
int x_[N], y_[N], c_[N];
int Xs[N], Ys[N];
vector<pr> a[N], event[N];
set s;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

namespace DC {
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
	#define exist_pd if (~x[id].tag) push_down(x[id], x[lc], x[rc])

	struct node {int v, coef, sum, tag;} x[N * 2];

	inline void update(node &ret, const node &l, const node &r) {ret.v = r.v, add(ret.sum = l.sum, r.sum);}

	inline void cover(node &ret, int v) {ret.tag = ret.v = v, ret.sum = (ll)ret.v * ret.coef % mod;}

	inline void push_down(node &ret, node &l, node &r) {cover(l, ret.tag), cover(r, ret.tag), ret.tag = -1;}

	void build(int id, int L, int R) {
		x[id].tag = -1;
		if (L == R) {x[id].v = c_[L], x[id].coef = y_[L], x[id].sum = (ll)x[id].v * x[id].coef % mod; return;}
		segc; build(lc, L, M), build(rc, M + 1, R);
		add(x[id].coef = x[lc].coef, x[rc].coef), update(x[id], x[lc], x[rc]);
	}

	void adj(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) return cover(x[id], v);
		segc; exist_pd;
		if (ql <= M) adj(lc, L, M, ql, qr, v);
		if (qr > M) adj(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}

	int bisect(int id, int L, int R, int v) {
		if (v > x[id].v) return R + 1;
		for (; L < R; ) {
			segc; exist_pd;
			id = (v <= x[lc].v ? (R = M, lc) : (L = M + 1, rc));
		}
		return L;
	}
}

int main() {
	int i, j, x, y, z, _, ans = 0, cur;
	set::iterator it; bool ret;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> C >> L;
	for (i = 0; i < n; ++i) cin >> x_[i] >> y_[i] >> c_[i], DC::D[i] = pr(x_[i], i);
	Xn = DC::Discretize(n), Xs[Xn] = L;
	for (i = 0; i < Xn; ++i) Xs[i] = DC::D[i].first;
	for (i = 0; i < n; ++i) x_[i] = DC::F[i], DC::D[i] = pr(y_[i], i);
	Yn = DC::Discretize(n), Ys[Yn] = L;
	for (i = 0; i < Yn; ++i) Ys[i] = DC::D[i].first;
	for (i = 0; i < n; ++i) y_[i] = DC::F[i], a[--c_[i]].EB(x_[i], y_[i]);
	for (i = 0; i < C; ++i) std::sort(a[i].begin(), a[i].end());
	std::adjacent_difference(Xs, Xs + Xn, x_), ++*x_,
	std::adjacent_difference(Ys, Ys + Yn, y_), ++*y_, L2 = L * (Ys[Yn - 1] + 1ll) % mod;
	for (x = Xn - 1; x >= 0; --x) {
		memset(c_, 0, Yn << 2), *c_ = *Ys;
		for (i = 0; i <= x; ++i) event[i].clear();
		for (i = 0; i < C; ++i) {
			for (; !a[i].empty() && a[i].back().first > x; a[i].pop_back());
			if (a[i].empty()) return cout << ans << '\n', 0;
			s.clear(), s.emplace(-1), s.emplace(Yn);
			for (j = (int)a[i].size() - 1; j >= 0; --j) {
				std::tie(z, y) = a[i][j], std::tie(it, ret) = s.emplace(y);
				if (ret) _ = *std::prev(it), event[z].EB(_ + 1, Ys[*++it]);
			}
			for (int e : s) {
				if (~e) up(c_[j + 1], Ys[e]);
				j = e;
			}
		}
		for (i = 1; i < Yn; ++i) up(c_[i], c_[i - 1]);
		ST::build(1, 0, Yn - 1), cur = 0;
		for (i = 0; i <= x; ++i) {
			cur = (cur + ll(L2 - ST::x[1].sum + mod) * x_[i]) % mod;
			for (const pr &e : event[i]) {
				z = ST::bisect(1, 0, Yn - 1, e.second);
				if (e.first < z) ST::adj(1, 0, Yn - 1, e.first, z - 1, e.second);
			}
		}
		ans = (ans + ll(Xs[x + 1] - Xs[x]) * cur) % mod;
	}
	cout << ans << '\n';
	return 0;
}