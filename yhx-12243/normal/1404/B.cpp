#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054, M = N * 2;

int n, E, s1, s2, d1, d2, ret, D1, D2;
int to[M], first[N], next[M];
int p[N], dep[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y;
	if (dep[x] > dep[ret]) ret = x;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1, dfs(y);
}

void work() {
	int i, u, v, w = 0;
	cin >> n >> s1 >> s2 >> d1 >> d2, E = 0;
	memset(first, 0, (n + 1) << 2);
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	ret = 1,  dep[ret] = p[ret] = 0, dfs(ret), D1 = ret;
	ret = D1, dep[ret] = p[ret] = 0, dfs(ret), D2 = ret;
	d1 = std::min(d1, dep[ret]), d2 = std::min(d2, dep[ret]);
	if (2 * d1 >= d2) {cout << "Alice\n"; return;}
	for (; s1 != s2; )
		if (dep[s1] > dep[s2]) s1 = p[s1], ++w;
		else s2 = p[s2], ++w;
	cout << (w <= d1 ? "Alice\n" : "Bob\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}