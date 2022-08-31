#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;
using std::vector;

typedef std::pair <int, int> pr;
const int N = 200054;

int R, C, X;
int r[N], c[N];
vector <int> ins[N], del[N];
vector <pr> qry[N];

// v2 <= u1 <= w2, v1 <= u2 <= w1
struct data {
	int u, v, w;
	inline bool accept(const data &B) const {return B.v <= u && u <= B.w && v <= B.u && B.u <= w;}
	inline void shrink(int x) {u -= x, v -= x, w -= x;}
} A[N], B[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace Cartesian {
	int n, *a, root;
	int stack[N], lc[N], rc[N];
	data b[N];

	inline void init(int n_, int *a_) {n = n_, a = a_;}

	int dfs(int n, int L, int R) {
		b[n].w = std::min(a[L - 1], a[R + 1]) - 1;
		b[n].u = b[n].v = a[n];
		if (~lc[n]) down(b[n].u, dfs(lc[n], L, n - 1));
		if (~rc[n]) down(b[n].u, dfs(rc[n], n + 1, R));
		return b[n].u;
	}

	void build() {
		int i, top = 0;
		memset(lc, -1, (n + 2) << 2), memset(rc, -1, (n + 2) << 2);
		for (i = 0; i <= n + 1; ++i) {
			for (; top && a[ stack[top] ] <= a[i]; --top) lc[i] = stack[top];
			if (top) rc[ stack[top] ] = i;
			stack[++top] = i;
		}
	}

	void work(data *ret) {
		int i;
		build(), dfs(rc[0], 1, n);
		for (i = 1; i <= n; ++i) ret[i] = b[i], ret[i].u = X - ret[i].u;
	}
}

namespace BIT {
	const int N = 400054;

	int x[N];

	inline int sum(int h) {int s = 0; for (; h >= 0; h &= h + 1, --h) s += x[h]; return s;}
	inline void add(int h, int v) {for (; h < N; h |= h + 1) x[h] += v;} 
	inline int range(int l, int r) {return sum(r) - sum(l - 1);}
}

int main() {
	int i, j, t, min = 0; long long ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> R >> C >> X, r[0] = r[R + 1] = c[0] = c[C + 1] = X + 2;
	for (i = 1; i <= R; ++i) cin >> r[i], down(r[i], X + 1); 
	for (j = 1; j <= C; ++j) cin >> c[j], down(c[j], X + 1);
	Cartesian::init(R, r), Cartesian::work(A),
	Cartesian::init(C, c), Cartesian::work(B);
	for (i = 1; i <= R; ++i) down(min, A[i].u);
	for (j = 1; j <= C; ++j) down(min, B[j].u);
	for (i = 1; i <= R; ++i) A[i].shrink(min);
	for (j = 1; j <= C; ++j) B[j].shrink(min);
/*
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j) {
			ans += A[i].accept(B[j]);
			if (A[i].accept(B[j])) {
				fprintf(stderr, "(%d, %d)\n", i, j);
			}
		}
*/
	for (i = 1; i <= R; ++i) ins[ A[i].v ].EB( A[i].u ), del[ A[i].w + 1 ].EB( A[i].u );
	for (j = 1; j <= C; ++j) qry[ B[j].u ].EB( B[j].v, B[j].w );
	for (t = 0; t < N; ++t) {
		for (int x : ins[t]) BIT::add(x, 1);
		for (int x : del[t]) BIT::add(x, -1);
		for (const pr &e : qry[t]) ans += BIT::range(e.first, e.second);
	}
	cout << ans << '\n';
	return 0;
}