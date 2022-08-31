#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 500054, M = N * 2;

int n, m, E = 0;
int to[M], first[N], next[M];
int p[N], parent[N], que[N];
int stamp = 0, tag[N];
int A[N], B[N];

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void bfs(int si) {
	int i, x, h, t = 1;
	*que = si;
	for (h = 0; h < t; ++h){
		x = que[h], p[x] = ancestor(x + 1);
		for (++stamp, i = first[x]; i; i = next[i]) tag[to[i]] = stamp;
		for (i = ancestor(1); i <= n; i = ancestor(i + 1))
			if (tag[i] != stamp)
				parent[i] = x, p[i] = ancestor(i + 1), que[t++] = i;
	}
}

namespace tree {
	int W;
	int *p = parent, fc[N], nc[N], deg[N];
	bool f[N];
	int cnt, buf[N], rt;

	inline void reset() {memset(fc, 0, (n + 1) << 2), memset(deg, 0, (n + 1) << 2);}
	inline void link(int x, int px) {nc[x] = fc[px], fc[px] = x, ++deg[px];}

	void dfs(int x) {
		int i, y; f[x] = true;
		for (y = fc[x]; y; y = nc[y]) {
			dfs(y);
			if (f[y]) f[x] = false;
		}
		if (!f[x]) {
//			fprintf(stderr, "elim %d\n", x);
			cnt = 0, rt = x;
			for (y = fc[x]; y; y = nc[y]) if (f[y]) buf[cnt++] = y;
			for (i = 0; i < cnt; ++i) y = buf[i], A[y] = W + i + 1, B[y] = W + i + 2;
			B[x] = W + 1, A[x] = W += cnt + 1;
		}
	}

	void main() {
		int i, j, y;
		W = 0;
		for (i = 1; i <= n; ++i) if (!p[i]) {
			if (!fc[i]) A[i] = B[i] = ++W; // single
			else {
				dfs(i);
				if (f[i]) {
//					fputs("danger !\n", stderr);
					buf[cnt++] = i, W -= cnt;
					for (j = 0; j < cnt; ++j) y = buf[j], A[y] = W + j + 1, B[y] = W + j + 2;
					B[rt] = W + 1, A[rt] = W += cnt + 1;
				}
			}
		}
		assert(W == n);
	}
}

void work() {
	int i, u, v;
	cin >> n >> m, E = 0;
	memset(first, 0, (n + 1) << 2);
	for (i = 0; i < m; ++i) cin >> u >> v, addedge(u, v);
	std::iota(p, p + (n + 2), 0);
	memset(parent, 0, (n + 1) << 2);
	for (i = 1; i <= n; i = ancestor(i + 1)) bfs(i);
	tree::reset();
	for (i = 1; i <= n; ++i) {
//		fprintf(stderr, "parent[%d] = %d\n", i, parent[i]);
		if (parent[i]) tree::link(i, parent[i]);
	}
	tree::main();
	for (i = 1; i <= n; ++i) cout << A[i] << (i == n ? '\n' : ' ');
	for (i = 1; i <= n; ++i) cout << B[i] << (i == n ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}