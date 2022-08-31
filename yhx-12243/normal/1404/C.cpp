#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef std::pair <int, int> pr;
const int N = 300054, INF = 0x3f3f3f3f;

int n, q;
int a[N];
int r[N], ans[N];
vector <int> qs[N];

inline pr min(const pr &x, const pr &y) {return x.first <= y.first ? x : y;}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h > 0; h &= h - 1) s += x[h]; return s;}
	void add(int h, int v) {for (; h <= n; h |= h - 1, ++h) x[h] += v;}
}

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {pr v; int tag;} x[1050000];

	void build(int id, int L, int R) {
		x[id].v = pr(n + 1, L), x[id].tag = 0;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v.first += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		x[id].v = min(x[lc].v, x[rc].v), x[id].v.first += x[id].tag;
	}
}

void main_loop() {
	int id;
	for (; ST::x[1].v.first <= 0; ) {
		id = ST::x[1].v.second;
//		fprintf(stderr, "elim %d\n", id);
		BIT::add(id, 1), ST::add(1, 1, n, id, id, n + 1);
		if (id < n) ST::add(1, 1, n, id + 1, n, -1);
	}
}

int main() {
	int i, pre;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 1; i <= n; ++i) cin >> a[i], a[i] = i - a[i];
	for (i = 0; i < q; ++i) cin >> pre >> r[i], r[i] = n - r[i], qs[pre + 1].EB(i);
	ST::build(1, 1, n);
	for (i = n; i; --i) {
//		fprintf(stderr, "set %d => %d\n", i, a[i]);
		if (a[i] >= 0) ST::add(1, 1, n, i, i, a[i] - (n + 1)), main_loop();
		for (int id : qs[i]) ans[id] = BIT::sum(r[id]);
	}
	for (i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}