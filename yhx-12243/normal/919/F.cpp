#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::unordered_map <int, int> map;
const int N = 500, N2 = N * N;

int n = 0, V, st[N];
map id;

void dfs(int d, int r, int S) {
	if (d == 4) {id.emplace(st[n] = S | r << 16, n), ++n; return;}
	for (int i = 0; i <= r; ++i) dfs(d + 1, r - i, S | i << 4 * d);
}

namespace G {
	const int N = N2, M = 1742500;

	int E = 0;
	int to[M], first[N], next[M];
	int deg[N], que[N], state[N];

	inline void addedge(int u, int v) {to[++E] = v, next[E] = first[u], first[u] = E, ++deg[v];}

	void toposort() {
		int h, t = 0, x, y, i;
		memset(state, -1, V << 2);
		for (i = 0; i < V; ++i) if (!deg[i]) state[i] = 0, que[t++] = i;
		for (h = 0; h < t; ++h)
			for (i = first[x = que[h]]; i; i = next[i]) if (!~state[y = to[i]]) {
				if (!state[x]) state[y] = 1, que[t++] = y;
				else if (!--deg[y]) state[y] = 0, que[t++] = y;
			}
	}
}

void init() {
	int i, j, k, f, s;
	dfs(0, 8, 0), assert(n == 495), V = n * n;
	for (i = 0; i < V; ++i) {
		f = st[i % 495], s = st[i / 495];
		for (j = 1; j < 5; ++j) if (f >> 4 * j & 15)
			for (k = 1; k < 5; ++k) if (s >> 4 * k & 15)
				G::addedge(i / 495 + id[f + (1 << 4 * ((j + k) % 5)) - (1 << 4 * j)] * 495, i);
	}
	G::toposort();
}

void work() {
	int i, flip, A = 0, B = 0, x;
	cin >> flip;
	for (i = 0; i < 8; ++i) cin >> x, A += 1 << 4 * x;
	for (i = 0; i < 8; ++i) cin >> x, B += 1 << 4 * x;
	x = flip ? G::state[id[B] + id[A] * 495] ^ 1 : G::state[id[A] + id[B] * 495],
	cout << (x >= 0 ? x ? "Alice\n" : "Bob\n" : "Deal\n");
}

int main() {
	int T; init();
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}