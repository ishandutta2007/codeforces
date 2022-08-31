#include <bits/stdc++.h>
#define lg2 std::__lg

typedef std::pair <int, int> pr;
const int N = 600054;

int n;
int p[N];

inline void up(pr &x, const pr &y) {x.first > y.first ? x.first = y.first : 0, x.second < y.second ? x.second = y.second : 0;}

namespace DCTree {
	enum type {leaf, disjunct, conjunct} I[N];

	pr st[20][N];
	int stack1[N], stack2[N], stack[N];
	int cnt, root, left[N], mid[N], right[N];

	void build_sparse_table() {
		int i, j, k = n; pr *f, *g = *st;
		for (j = 0; 1 << (j + 1) <= n; ++j) {
			f = g, g = st[j + 1], k -= 1 << j;
			for (i = 1; i <= k; ++i)
				up(g[i] = f[i], f[i + (1 << j)]);
		}
	}

	inline bool is_consecutive(int L, int R) { // [L, R)
		int c = lg2(R - L); pr ans = st[c][L]; up(ans, st[c][R - (1 << c)]);
		return ans.second - ans.first == R - L - 1;
	}

	namespace ST {
		#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
		struct node {int v, tag;} x[N * 4];

		void build(int id, int L, int R) {
			x[id].v = L, x[id].tag = 0;
			if (L == R) return;
			segc; build(lc, L, M), build(rc, M + 1, R);
		}

		void add(int id, int L, int R, int ql, int qr, int v) {
			if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
			segc;
			if (ql <= M) add(lc, L, M, ql, qr, v);
			if (qr > M) add(rc, M + 1, R, ql, qr, v);
			x[id].v = std::min(x[lc].v, x[rc].v) + x[id].tag;
		}

		int find_suf(int id, int L, int R, int v, int cv = 0) {
			if (cv + x[id].v > v) return -1;
			if (L == R) return L;
			segc, p = find_suf(lc, L, M, v, cv += x[id].tag);
			return ~p ? p : find_suf(rc, M + 1, R, v, cv);
		}
	}

	int pa[N], fc[N], nc[N], deg[N];

	inline void link(int x, int px) {pa[x] = px, nc[x] = fc[px], fc[px] = x, ++deg[px];}

	void build() {
		int i, l, top1 = 0, top2 = 0, top = 0, &v = root; cnt = n;
		for (i = 1; i <= n; ++i) st[0][i] = pr(p[i], p[i]), left[i] = right[i] = i, I[i] = leaf;
		build_sparse_table(), ST::build(1, 1, n);
		for (i = 1; i <= n; ++i) {
			for (; top1 && p[i] > p[ stack1[top1] ]; --top1)
				ST::add(1, 1, n, stack1[top1 - 1] + 1, stack1[top1], p[i] - p[ stack1[top1] ]);
			for (; top2 && p[i] < p[ stack2[top2] ]; --top2)
				ST::add(1, 1, n, stack2[top2 - 1] + 1, stack2[top2], p[ stack2[top2] ] - p[i]);
			stack1[++top1] = stack2[++top2] = i;
			l = ST::find_suf(1, 1, n, i);
			for (v = i; top && left[ stack[top] ] >= l; --top)
				if (I[ stack[top] ] == conjunct && is_consecutive(mid[ stack[top] ], i + 1))
					right[ stack[top] ] = i, link(v, stack[top]), v = stack[top];
				else if (is_consecutive(left[ stack[top] ], i + 1)) {
					I[++cnt] = conjunct, link(stack[top], cnt), link(v, cnt);
					left[cnt] = left[ stack[top] ], right[cnt] = i, mid[cnt] = left[v], v = cnt;
				} else {
					I[++cnt] = disjunct, link(v, cnt);
					for (; top && !is_consecutive(left[ stack[top] ], i + 1); --top)
						link(stack[top], cnt); link(stack[top], cnt);
					left[cnt] = left[ stack[top] ], right[cnt] = i, v = cnt;
				}
			stack[++top] = v;
		}
	}
}

int main() {
	int i, u, v; long long ans;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", &u, &v), p[u] = v;
	DCTree::build(), ans = DCTree::cnt;
	for (i = n + 1; i <= DCTree::cnt; ++i)
		if (DCTree::I[i] == DCTree::conjunct && (v = DCTree::deg[i]) > 2)
			ans += (v - 2ll) * (v + 1ll) / 2;
	printf("%lld\n", ans);
	return 0;
}