#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef std::unordered_set <u64> set;
const int N = 100054, M = N * 2;

int V, E, K, Es = 0;
int to[M], first[N], next[M];
int deg[N], deg_raw[N];
int p[N], size[N], size1[N];
int que[N];
int len = 0, ans[N];
bool alive[N];
set S;

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es, ++deg[u];
	to[++Es] = u, next[Es] = first[v], first[v] = Es, ++deg[v];
}

void un(int x, int y) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return;
	p[x] = y, size[y] += size[x], size1[y] += size1[x];
}

inline bool check(int u, int v) {
	return S.count(u < v ? u | (u64)v << 32 : v | (u64)u << 32);
}

void work() {
	int i, j, u, v, x, y, h, t = 0;
	cin >> V >> E >> K, Es = len = 0;
	memset(deg, 0, (V + 1) << 2);
	memset(first, 0, (V + 1) << 2);
	memset(alive, true, V + 1);
	S.clear();
	for (i = 1; i <= E; ++i) {
		cin >> u >> v, addedge(u, v);
		if (u > v) std::swap(u, v);
		S.emplace(u | (u64)v << 32);
	}
	if (K == 1) {cout << "2\n1\n"; return;}
	memcpy(deg_raw, deg, (V + 1) << 2);
	for (i = 1; i <= V; ++i) if (deg[i] < K) que[t++] = i;
	for (h = 0; h < t; ++h) {
		alive[x = que[h]] = false;
		for (i = first[x]; i; i = next[i])
			if (alive[y = to[i]] && --deg[y] == K - 1) que[t++] = y;
	}
	if (t < V) {
		for (i = 1; i <= V; ++i) if (alive[i]) ans[len++] = i;
		cout << '1' << ' ' << len << '\n';
		for (i = 0; i < len; ++i) cout << ans[i] << (i == len - 1 ? '\n' : ' '); 
		return;
	}
	if (K * (K - 1ll) > 2 * E) {cout << "-1\n"; return;}
	memcpy(deg, deg_raw, (V + 1) << 2);
	memset(alive, true, V + 1);
	for (t = 0, i = 1; i <= V; ++i) if (deg[i] < K - 1) que[t++] = i;
	for (h = 0; h < t; ++h) {
		alive[x = que[h]] = false;
		for (i = first[x]; i; i = next[i])
			if (alive[y = to[i]] && --deg[y] == K - 2) que[t++] = y;
	}
	if (t <= V - K) {
		for (i = 1; i <= V; ++i) if (alive[i] && deg[i] < K) que[t++] = i;
		for (; h <= V - K; ++h) {
			alive[x = que[h]] = false;
			if (deg[x] == K - 1) {
				len = 0, ans[len++] = x;
				for (i = first[x]; i; i = next[i])
					if (alive[y = to[i]]) ans[len++] = y;
				assert(len == K);
				for (i = 0; i < K - 1; ++i) {
					for (j = i + 1; j < K; ++j)
						if (!check(ans[i], ans[j])) break;
					if (j < K) break;
				}
				if (i == K - 1) {
					cout << '2' << '\n';
					for (i = 0; i < len; ++i) cout << ans[i] << (i == len - 1 ? '\n' : ' '); 
					return;
				}
			}
			for (i = first[x]; i; i = next[i])
				if (alive[y = to[i]] && --deg[y] == K - 1) que[t++] = y;
		}
	}
	cout << "-1\n";
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}