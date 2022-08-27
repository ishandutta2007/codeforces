#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1054, M = N * 4;

int V, E, Es;
int w[N], v[N];
int to[M], first[N], next[M];
int que[N], par[N];
ll D[N];
bool reachable[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es,
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

inline void extend(int x) {for (; par[x]; x = par[x]) reachable[x] = true;}

bool augment(ll D0) {
	int i, h, t = 0, x, y;
	memset(par, 0, (V + 1) << 2), memset(D, 0, (V + 1) << 3);
	for (i = 1; i <= V; ++i) if (reachable[i]) que[t++] = i, D0 += v[i];
	for (h = 0; h < t; ++h) D[ que[h] ] = D0;
	for (h = 0; h < t; ++h) {
		x = que[h];
		for (i = first[x]; i; i = next[i])
			if (y = to[i], D[x] >= w[y]) {
				if (y == par[x]) continue;
				if (reachable[y]) {
					if (reachable[x]) continue;
					return extend(x), true;
				}
				if (par[y]) return extend(x), extend(y), true;
				D[y] = D[x] + v[y], par[y] = x, que[t++] = y;
			}
	}
	return false;
}

bool check(int v0) {
	memset(reachable, false, V + 1), reachable[1] = true;
	for (; augment(v0); );
	return !std::count(reachable + 1, reachable + (V + 1), false);
}

void work() {
	int i, u, v, L = 0, R = 0, M;
	cin >> V >> E, Es = 0,
	memset(first, 0, (V + 1) << 2);
	for (i = 2; i <= V; ++i) cin >> w[i], up(R, ++w[i]);
	for (i = 2; i <= V; ++i) cin >> ::v[i];
	for (i = 0; i < E; ++i) cin >> u >> v, addedge(u, v);
	for (; L < R; ) check(M = (L + R) / 2) ? R = M : L = M + 1;
	cout << L << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}