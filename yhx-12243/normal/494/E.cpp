#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 100054;

struct rect {
	int r1, r2, c1, c2;
	rect () {}
	rect (int r_1, int r_2, int c_1, int c_2) : r1(r_1), r2(r_2), c1(c_1), c2(c_2) {}
	friend std::istream & operator >> (std::istream &in, rect &B) {return in >> B.r1 >> B.c1 >> B.r2 >> B.c2;}
	inline rect scale(int bit) {return rect(((r1 - 1) >> bit) + 1, r2 >> bit, ((c1 - 1) >> bit) + 1, c2 >> bit);}
	inline bool empty() const {return r1 > r2 || c1 > c2;}	
} a[N], b[N];

struct sweepLine {
	int r, c1, c2, v;
	sweepLine () {}
	sweepLine (int row, int c_1, int c_2, int coef) : r(row), c1(c_1), c2(c_2), v(coef) {}
	inline bool operator < (const sweepLine &B) const {return r < B.r || (r == B.r && v > B.v);}
} sl[N];

int n, m, mi, R, K;
int sc[N];

inline int max(const int x, const int y) {return x < y ? y : x;}

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

	struct node {int v, cnt;} x[262154];

	inline void update(node &ret, const node &l, const node &r, int L, int R) {
		ret.cnt = ret.v ? sc[R] - sc[L - 1] : L == R ? 0 : l.cnt + r.cnt;
	}

	void build(int id, int L, int R) {
		x[id].v = x[id].cnt = 0;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		segc;
		if (ql <= L && R <= qr) return x[id].v += v, update(x[id], x[lc], x[rc], L, R);
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc], L, R);
	}
}

bool solve() {
	int i; bool ret = false;
	if (!m) return ret;
	for (i = 0; i < m; ++i) DC::D[i] = pr(a[i].c1 - 1, i), DC::D[i + m] = pr(a[i].c2, i + m);
	R = DC::Discretize(2 * m);
	for (i = 0; i < R; ++i) sc[i] = DC::D[i].first;
	for (i = 0; i < m; ++i)
		sl[i] = sweepLine(a[i].r1, DC::F[i], DC::F[i + m], 1), sl[i + m] = sweepLine(a[i].r2 + 1, DC::F[i], DC::F[i + m], -1);
	std::sort(sl, sl + 2 * m), ST::build(1, 1, R - 1);
	for (i = 0; i < 2 * m; ++i) {
		if (i && (sl[i - 1].r ^ sl[i].r) & 1) ret ^= ST::x[1].cnt & 1;
		ST::add(1, 1, R - 1, sl[i].c1 + 1, sl[i].c2, sl[i].v);
	}
	return ret;
}

int main() {
	int i, B;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> mi >> K;
	for (i = 0; i < mi; ++i) cin >> b[i];
	for (B = 0; 1 << B <= K; ++B) {
		for (m = i = 0; i < mi; ++i) a[m] = b[i].scale(B), m += !a[m].empty();
		if (solve()) return cout << "Hamed\n", 0;
	}
	return cout << "Malek\n", 0;
}